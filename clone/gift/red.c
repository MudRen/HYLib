// ���

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIY"20W���ƽ�"NOR, ({"20Wgold"}));
	set_weight(10);
    set("value", 0);
set("no_steal",1);
set("liwu",1);
set("no_beg",1);
    set("no_put",1);
    set("no_get","ÿ����ֻ��һ������Ҫ��ô̰�ģ�\n");
    set("no_drop","��ô���Ķ�����Ҳ�ӣ���\n");
	if (clonep())
		set_default_object(__FILE__);
	else {
                set("long", "һ��"+HIY"20�����ƽ��֧Ʊ��"NOR+"�ƺ����Զһ�(duihuan)��\n");
                set("unit", "��");
	}
}
  void init()
{
  add_action("do_open","duihuan");
}
int do_open()
{
object ob;
        this_player()->start_busy(30);
        this_player()->add("combat_exp", 200+random(100));
        this_player()->add("potential",150+random(100));
        message_vision("$N�һ���1��20�����ƽ��֧Ʊ���Ǽٱң�$N���̱�Ѻ�����ٸ�!\n", this_player());
        this_player()->move("/d/pingan/ymzhengting");
	destruct(this_object());
	return 1;
}

void owner_is_killed()
{
	destruct(this_object());
}
