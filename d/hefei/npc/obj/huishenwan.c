
inherit ITEM;
#include <ansi.h>
int do_fu(string arg);
void create()
{
   set_name(GRN"������"NOR, ({ "huishen wan","wan" }));
   set_weight(100);
   set("unit", "��");
   set("long","�����������˵�ҩ,����Է���(fu wan)����.\n");
   set("value", 2000);
   
}

void init()
{
	add_action("do_fu","fu");
}
int do_fu(string arg)
{
	object me,ob;int i;
	ob=this_object();me=this_player();
	if(!arg||(arg!="wan"&&arg!="��"))
		return notify_fail("��Ҫ����ʲô?\n");
	if(me->query("sen")==me->query("max_jing"))
		return notify_fail("��ľ���ܺ�,��ʲôҩ��?\n");
    i=me->query("max_jing")-me->query("sen");
	if(i<=10)
	me->add("sen",i);
	else me->add("sen",i/5);
	message_vision("$N������һ��[������].\n",me);
	destruct(ob);
	return 1;
}