inherit ITEM;

void create()
{
        set_name("��ʯ", ({ "ju shi", "shi"}));
        set_weight(40000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ����Ȼ�γɵľ�ʯ��\n");
        }
        setup();
}