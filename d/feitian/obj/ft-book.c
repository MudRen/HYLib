//by diabio
inherit ITEM;
#include <ansi.h>
void create()
{
	set_name("��������������", ({ "bao dian", "book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",
"�����������Ĳ���֮�顣\n");
		set("value", 0);
		set("material", "paper");
		}
}


void init()
{
	add_action("do_study","study");
	add_action("do_study","du");
}

int do_study(string arg)
{
	object me;
	me=this_player();
	if (!arg="bao dian" || !arg="book")
		return notify_fail("��Ҫ��ʲô��\n");
        message_vision("$N�߿�������ָպ����ĭ��һҳһҳ�ط����ŷ�������������,��ͻ��̲�ס�İ����������˼���\n",me);
	me->start_busy(5);
     remove_call_out("yapian_poison");
      call_out("yapian_poison", 40);
	return 1;
}

int yapian_poison()
{
	object me=this_player();
	message("channel:chat",
			HIY"��������"HIC"��Ż���������ͻȻ����һ�����������������ˣ����������䲻����!
\n"NOR,users());
	call_out("mi_tan",10);
	return 1;
}

int mi_tan()
{
	message("channel:chat",
			HIY"��������������"HIC"�ȹ���ʮ�����ڽе���糴彣��ȥ�������龭����
\n"NOR,users());
	call_out("zi_bai",10);
	return 1;
}

int zi_bai()
{
	message("channel:chat",
                        HIY"��ҩ�̡�"HIC"�ߺͻݼ���:������ô���ˣ��ǿ�������ǰ���˱�����ѻƬʱ��������׵ģ�������"HIR"ѻƬ����\n
"HIC"            ��֮�������������ô��ģ����ǽ���źõ���������λֻ��.....\n"NOR,users());
	call_out("zi_bai2",10);
	return 1;
}

int zi_bai2()
{
	message("channel:chat",
                        HIY"��������������"HIC"ĳ������̾�˿��������������\n"NOR,users());
	call_out("zi_bai3",10);
	return 1;
}
int zi_bai3()
{
	object me=this_player();
	object ob;
	ob=this_object();
	message("channel:chat",
			HIY"�����Ͼ��ӡ�"HIB+ me->query("name") +HIC"�������ش��һ��������.T.M.D.˵����°װ�ĭ�����˹�ȥ��\n"NOR,users());
	destruct(ob);
	return 1;
}
