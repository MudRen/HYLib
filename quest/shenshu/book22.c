#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(BLU"���Ƶ�һ��"NOR, ({ "fyblade" }) );
            set("no_put", 1);
            set("value", 0);
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
	        
            set("unit", "��");
            set("material", "paper");
            set("long", "����֮һ,��������������еĵ������߳����Ӻ��������µ���������(zu)��\n");
          }

    setup();
}
void init()
{
    add_action("do_zu","zu");
}
int do_zu()
{
	object me,newbook,ob;
	object *inv;
	int sizeinv;

	me = this_player();
	newbook =new(__DIR__"4book");
 //if (!present("fengling", me)
 //||!present("bclangzi",me)
 //||!present("skyblade",me))
		inv=all_inventory(me);
		sizeinv=sizeof(inv);
	
		while (sizeinv--)
		{
       			if (inv[sizeinv]->is_character())  
     				return notify_fail("���Ȱ����ϵ��˷��°�!!\n");
       		
		}
    if (!(ob = present("fengling", me)) ||
        !(ob = present("bclangzi", me)) ||
        !(ob = present("skyblade", me)))
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
      message_vision("$N�Ѵӻ��з����ı߳����ӣ������еĵ������������µ��������е�������ºϲ�����һ����\n", me);
	newbook->move(me);
	destruct(present("fengling",me));
	destruct(present("bclangzi",me));
	destruct(present("skyblade",me));
	destruct(this_object());}
return 1;
}
