inherit ITEM;

void create()
{
        set_name( "����",({"table" }));
        set_weight(30000);
        set_max_encumbrance(18000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "wood");
                set("value", 2000);
                set("long", "���������ӷ�������ܾ��ˣ��������һ�������̣���һ��ǩͲ��\n" );
                set("no_sell", "���������������������");
        }        
        setup();
}
void init()
{
        add_action("do_look","see");
        add_action("do_get","get");
}
int do_look(string arg)
{
        object ob, who;
        ob = this_object();
        who = this_player();
        if(!arg || arg !="table")
                return notify_fail("��Ҫ��ʲô? \n");
        else   return notify_fail("��������ſ��������˯���أ�������Ҫ��knock�����Ӳ��ܽ������ˡ�\n");               
}
int do_get(string arg)
{
        object ob, me;
        ob = this_object();
        me = this_player();
        if(arg && arg =="table"){
                write ("��Ҫ�������ò��ã�����������Ψһ�ĲƲ��ˡ�\n");
                 return 1;
        }
        return 0;
}

