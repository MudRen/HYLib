// ��������� /ADDED BY KEINXIN

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIY"�»����"NOR, ({"xinhun heli", "heli", "libao"}));
	set_weight(10);
set("no_drop", 1);
set("no_put", 1);
    set("no_bug", 1);
    set("no_steal", 1);
    set("no_get", 1);
    set("value", 0);
	if (clonep())
		set_default_object(__FILE__);
	else {
    set("no_give","�����»�ĺ�����ô��������ˣ�\n");
set("no_drop", 1);
set("no_put", 1);
    set("no_get", 1);
    set("no_give", 0);
    set("value", 0);
		set("long", "һ���ô��������ɵ�"+HIY"�»����"NOR+"�Ǻ���2����ʦף�����˵�����ƺ����Դ�(opengift)��\n");
		set("unit", "��");
	}
}
  void init()
{
  add_action("do_open","opengift");
}
int do_open()
{
	int exp,pot;
	object me = this_player();
object ob;
        exp = 2100+random(5000);
	      pot = exp/3;
	this_player()->add("combat_exp",exp);
	this_player()->add("potential",pot);
        ob=new("/clone/money/gold");
        ob->set_amount(100);
        ob->move(this_player());
	this_player()->start_busy(50);
	message_vision("$N�����»���񣬾����Լ��ֱ�������һЩ !�������滹�кܶ�ƽ�!\n", this_player());
	tell_object(me,HIY"�㱻�����ˣ�һ�����ƽ�\n" +
             chinese_number(exp) + "��ʵս����\n"+
             chinese_number(pot) + "��Ǳ��\n"NOR);
	destruct(this_object());
	return 1;
}
void owner_is_killed()
{
	destruct(this_object());
}