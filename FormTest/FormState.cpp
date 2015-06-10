#include "FormState.h"


FormState::FormState()
{
    initComponents();
}

FormState::~FormState()
{

}

void FormState::initComponents(void)
{
    lblName.setCaption("Name");
    tbName.setDimension(120, 20);

    StiGame::Gui::ItemPair pair;
    pair.label = &lblName;
    pair.field = &tbName;

    formLayout.addPair(pair);

    add(&formLayout);
}

void FormState::onResize(int m_width, int m_height)
{
    formLayout.setDimension(m_width, m_height);
    GuiState::onResize(m_width, m_height);
}
