#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIB"Բ���䵶"NOR, ({ "wandao" }) );
            set("no_put", 1);
            set("value", 0);
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
	        
            set("unit", "��");
            set("material", "paper");
            set("long", "����֮һ,������������ү�Ľ�����(zhuangding)�ˡ�\n");
          }

    setup();
}
void init()
{
    add_action("do_zhuangding","zhuangding");
}
int do_zhuangding()
{
	object me,newbook,ob;
	me = this_player();
	newbook =new(__DIR__"xiebook");
// if (!present("xiesword",me))
    if (!(ob = present("xiesword",me)) )
	tell_object(me,"�����û��.\n");
else{
    if(!ob->query("dynamic_quest"))
	return notify_fail("�������мٻ��ɡ�\n");
       message_vision("$N�Ѵӻ��з�������ү�Ľ��������е�Բ�����ϲ�����һ����\n", me);
	newbook->move(me);
	destruct(present("xiesword",me));
	destruct(this_object());}
return 1;
}
