inherit ITEM;

void create()
{
        set_name("�͵�", ({ "you deng" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "յ");
                set("long", "��ڵ��͵�,���ϸ���һ�����.\n");
                set("value", 50);
        }
}


