// lingzhi.c ǧ����֥
//����(lywin)2000/4/22

#include <ansi.h>
inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_eat", "qifu");

}
void create()
{
        set_name(HIY"����"NOR, ({"xyanhu"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
    set("no_give","ÿ����ֻ��һ�����㶼��ô�󷽣�\n");
    set("value", 0);
set("liwu",1);
set("no_steal",1);
set("no_beg",1);
    set("no_put",1);
    set("no_get","ÿ����ֻ��һ������Ҫ��ô̰�ģ�\n");
    set("no_drop","��ô���Ķ�����Ҳ�ӣ���\n");

                set("unit", "��");
                set("long", "����һ��������xyanhu),��˵��˵�����������ң�\n����������ʮ�����ˣ���Щ���ƺͰ׷���һ����������ģ����\n������Ц��������������۸�(qifu)����\n");

		set("value", 0);
	}
	setup();
}

int do_eat(string arg)
{
	if (!id(arg))
        return notify_fail("��Ҫ�۸�˭��\n");
        this_player()->start_busy(20);
        this_player()->add("max_neili",10);
        this_player()->add("potential",500);
        this_player()->add("combat_exp",1000);
        message_vision("$N�ɹ����۸��˱�����������������1000����500Ǳ�ܺ�10��������\n", this_player());
	destruct(this_object());
	return 1;
}

void owner_is_killed()
{
	destruct(this_object());
}
