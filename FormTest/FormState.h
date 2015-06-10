#ifndef FORMSTATE_H
#define FORMSTATE_H

#include <GuiState.h>
#include <FormLayout.h>
#include <Label.h>
#include <TextBox.h>

class FormState :
        public StiGame::Gui::GuiState
{
public:
    FormState();
    virtual ~FormState();
private:
    StiGame::Gui::FormLayout formLayout;

    StiGame::Gui::Label lblName;
    StiGame::Gui::TextBox tbName;

    void initComponents(void);

    void onResize(int m_width, int m_height);
};

#endif // FORMSTATE_H
