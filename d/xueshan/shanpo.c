 //      shanpo.c ����̨

#include <ansi.h>

inherit ROOM;


void create()
{
        set("short",HIW"����̨"NOR);
        set("long",@LONG 
���Ǹ���Բ���������ɵ���Ȼƽ̨���˴��ѽӽ���ѩɽ���壬����£�
Ⱥɽ��ױ�ع�������ƬƬ���ƣ��������ؿ�����������������˵����ӽ���
�磬����˵������ֱ����ͥ����ͷ��������������������ǰ��Զ�����ͱ�ֱ
�ʣ�û��·�ˡ�
LONG);
        set("exits",([
                "southdown": __DIR__"xuelu3",
                "east": __DIR__"binglinfeng"
        ]));

        setup();
}

void init()
{

        mixed *local;

        local = localtime(time() * 60);
        if (local[2] < 11 || local[2] > 13) {
	message_vision(HIW
"������ѩ����ͷ�������˹���������$N�������ۡ�ͻȻ��ɽ�±�����һ����ѩ��$N��������������ͷ�ϣ�\n"NOR,this_player());
	message_vision(HIR"$N���²��ȣ�˳��ɽ�µ�����ȥ��\n"NOR,this_player());
    this_player()->move(__DIR__"xuegu");
    this_player()->unconcious();
        }
	add_action("do_climb","climb");
}

int do_climb(string arg)
  {
        object me ;
	int skill;
        me = this_player();
	skill = me->query_skill("dodge");
        if ( arg != "up" ) 
             return notify_fail("��Ҫ�ʵ����\n");

	if (me->is_fighting())
		return notify_fail("�㻹���Ȱѵ��˽���˰ɡ�\n");

	if (skill<100)
		return notify_fail("���·�������Ṧ����ۿۣ���������Ҫ���������С�\n");

        if ((!present("bing gao", this_player())) || (!present("ding xie", this_player()))) 
                return notify_fail("ʯ���ϸ����˺����㣬̫���ˣ������޴ӽ�����\n");

		message_vision("$Nʩչ�Ṧ���ֽŲ��ã�С������س�����������ȥ��\n", me);
		me->move(__DIR__"jueding");
		return 1;
}	

