#include <pu/element/TextBlock.hpp>

namespace pu::element
{
    TextBlock::TextBlock(s32 X, s32 Y, std::string Text, s32 FontSize) : Element::Element()
    {
        this->x = X;
        this->y = Y;
        this->text = Text;
        this->clr = { 0, 0, 0, 255 };
        this->fnt = render::LoadDefaultFont(FontSize);
        this->fsize = FontSize;
        this->ntex = render::RenderText(this->fnt, Text, this->clr);
    }

    TextBlock::~TextBlock()
    {
        if(this->fnt != NULL)
        {
            render::DeleteFont(this->fnt);
            this->fnt = NULL;
        }
        if(this->ntex != NULL)
        {
            render::DeleteTexture(this->ntex);
            this->ntex = NULL;
        }
    }

    s32 TextBlock::GetX()
    {
        return this->x;
    }

    void TextBlock::SetX(s32 X)
    {
        this->x = X;
    }

    s32 TextBlock::GetY()
    {
        return this->y;
    }

    void TextBlock::SetY(s32 Y)
    {
        this->y = Y;
    }

    s32 TextBlock::GetWidth()
    {
        return this->GetTextWidth();
    }

    s32 TextBlock::GetHeight()
    {
        return this->GetTextHeight();
    }

    s32 TextBlock::GetTextWidth()
    {
        return render::GetTextWidth(this->fnt, this->text);
    }

    s32 TextBlock::GetTextHeight()
    {
        return render::GetTextHeight(this->fnt, this->text);
    }

    std::string TextBlock::GetText()
    {
        return this->text;
    }

    void TextBlock::SetText(std::string Text)
    {
        this->text = Text;
        render::DeleteTexture(this->ntex);
        this->ntex = render::RenderText(this->fnt, Text, this->clr);
    }

    void TextBlock::SetFont(render::NativeFont Font)
    {
        render::DeleteFont(this->fnt);
        this->fnt = Font;
        render::DeleteTexture(this->ntex);
        this->ntex = render::RenderText(Font, this->text, this->clr);
    }

    draw::Color TextBlock::GetColor()
    {
        return this->clr;
    }

    void TextBlock::SetColor(draw::Color Color)
    {
        this->clr = Color;
        render::DeleteTexture(this->ntex);
        this->ntex = render::RenderText(this->fnt, this->text, Color);
    }

    void TextBlock::OnRender(render::Renderer *Drawer)
    {
        s32 rdx = this->GetProcessedX();
        s32 rdy = this->GetProcessedY();
        Drawer->RenderTexture(this->ntex, rdx, rdy);
    }

    void TextBlock::OnInput(u64 Down, u64 Up, u64 Held, bool Touch, bool Focus)
    {
    }
}