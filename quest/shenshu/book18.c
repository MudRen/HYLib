#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(YEL"��˧����"NOR, ({ "xscq" }) );
            set("no_put", 1);
            set("value", 0);
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
	        
            set("unit", "��");
            set("material", "paper");
            set("long", "����֮һ,����������½С��Ͳ�ӥ�������(zhuang)�ɴ���ϵ�С�\n");
          }

    setup();
}
void init()
{
    add_action("do_zhuang","zhuang");
}
int do_zhuang()
{
	object me,newbook,ob;
		object *inv;
	int sizeinv;

	me = this_player();
	newbook =new(__DIR__"chuanqi");
// if (!present("bycq", me)||!present("luxf",me))
		inv=all_inventory(me);
		sizeinv=sizeof(inv);
	
		while (sizeinv--)
		{
       			if (inv[sizeinv]->is_character())  
     				return notify_fail("���Ȱ����ϵ��˷��°�!!\n");
       		
		}
    if (!(ob = present("bycq", me)) ||
        !(ob = present("luxf", me)))
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
        message_vision("$N�Ѵӻ��з�����½С��Ͳ�ӥ���棬�����е���˧����ϲ�����һ����\n", me);
	newbook->move(me);
	destruct(present("bycq",me));
	destruct(present("luxf",me));
	destruct(this_object());}
return 1;
}
