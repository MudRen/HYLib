//table.c ��ױ̨
inherit ITEM;
void create()
{
        set_name("������", ({ "bigbox" , "big box", "box"}) );
        set_weight(5000);
        set_max_encumbrance(8000000);
        set("no_shown", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("no_get", 1);
                set("long", "����һ�������ӡ�\n");
                set("value", 0);
        }
}
int is_container() { return 1; }
