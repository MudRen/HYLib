#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIG"��������"NOR, ({ "cdjh" }) );
            set("no_put", 1);
            set("value", 0);
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
	         
            set("unit", "��");
            set("material", "paper");
            set("long", "����֮һ,���������������޵У���į���֣�������ѩ����(redo)��\n");
          }

    setup();
}
void init()
{
    add_action("do_redo","redo");
}
int do_redo()
{
	object me,newbook,ob;
	object *inv;
	int sizeinv;
	me = this_player();
	newbook =new(__DIR__"xia");
// if (!present("szwudi", me)
// ||!present("jmgaoshou",me)
// ||!present("txsnow",me))
		inv=all_inventory(me);
		sizeinv=sizeof(inv);
	
		while (sizeinv--)
		{
       			if (inv[sizeinv]->is_character())  
     				return notify_fail("���Ȱ����ϵ��˷��°�!!\n");
       		
		}
    if (!(ob = present("szwudi", me)) ||
        !(ob = present("jmgaoshou", me)) ||
        !(ob = present("txsnow", me)))	
	tell_object(me,"�����û��.\n");
     else{
        if( ob->query("ownmake"))
	return notify_fail("�������мٻ��ɡ�\n");
        if(userp(ob))
	return notify_fail("�������мٻ��ɡ�\n");
        if( ob->is_character() || ob->is_corpse() )
	return notify_fail("�������мٻ��ɡ�\n");
    if(!ob->query("dynamic_quest"))
	return notify_fail("�������мٻ��ɡ�\n");
       message_vision("$N�Ѵӻ��з����������޵У���į���֣�������ѩ�������еĴ��������ϲ�����һ����\n", me);
	newbook->move(me);
	destruct(present("szwudi",me));
	destruct(present("jmgaoshou",me));
	destruct(present("txsnow",me));
	destruct(this_object());}
return 1;
}
