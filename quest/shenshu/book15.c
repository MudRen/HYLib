#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIR"����˫��"NOR, ({ "juedsj" }) );
            set("no_put", 1);
            set("value", 0);
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
	        
            set("unit", "��");
            set("material", "paper");
            set("long", "����֮һ��\n");
          }

    setup();
}

void init()
{
    add_action("do_zhuang","he");
}
int do_zhuang(string arg)
{
	object me,newbook,ob;
	object *inv;
	int sizeinv;
	me = this_player();


 	if (arg!="gulongbooka")
	return notify_fail("��Ҫ�ϲ�ʲô��\n");
		inv=all_inventory(me);
		sizeinv=sizeof(inv);
	
		while (sizeinv--)
		{
       			if (inv[sizeinv]->is_character())  
     				return notify_fail("���Ȱ����ϵ��˷��°�!!\n");
       		
		}
	newbook =new(__DIR__"gbook1");

    if (!(ob = present("ywcq", me)) ||
        !(ob = present("drwu", me)) ||
!(ob = present("xscq", me)) ||
!(ob = present("bycq", me)) ||
!(ob = present("luxf", me)) ||
!(ob = present("wandao", me)) 
        )
	tell_object(me,"�����û��.\n");
  else {
        if( ob->query("ownmake"))
	return notify_fail("�������мٻ��ɡ�\n");
        if(userp(ob))
	return notify_fail("�������мٻ��ɡ�\n");
        if( ob->is_character() || ob->is_corpse() )
	return notify_fail("�������мٻ��ɡ�\n");
    if(!ob->query("dynamic_quest"))
	return notify_fail("�������мٻ��ɡ�\n");
        message_vision("$N�Ѵӻ��з������߱���������д�����飬������һ����\n", me);
	newbook->move(me);
	destruct(present("ywcq",me));
	destruct(present("drwu",me));
	destruct(present("xscq",me));
	destruct(present("bycq",me));
	destruct(present("luxf",me));
	destruct(present("wandao",me));

	destruct(this_object());}
return 1;
}
