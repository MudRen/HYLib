inherit ITEM;

void create()
{
	set_name("����", ({ "diaoyu gan" }) );
	set_weight(30000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ�ѵ���,���������װ(zhuang)�����\n");
		set("no_drop","��Ҫ�Ҷ����ⶫ������ʹ��\n");
		set("no_get",1);
		set("no_give",1);
		set("no_steal",1);
		set("no_put",1);
                set("yuer",1);	
		set("unit", "��");
		set("value", 100);
	}
}
void init()
{
   add_action("do_open","zhuang");
}
int do_open(string arg)
{ 
    object me=this_player(),ob;
ob=this_object();
        if( ob->query("yuer"))
                        return notify_fail("�����Ѿ�װ������\n");

        if( me->is_busy() )
                        return notify_fail("����æ���أ�\n");

        if (me->is_fighting()) 
        return notify_fail("���������������!\n");

    tell_object(me,"��ӵ�������һ����򾣬װ������ϡ�\n");
me->start_busy(8);
ob->set("yuer",1);
        return 1;
}