inherit ITEM;

void create()
{
        set_name("��������", ({ "tie li" }) );
        set_weight(9000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�Ѿ����������,���ϱ���һ���.\n");
                set("value", 100);
        }
}


