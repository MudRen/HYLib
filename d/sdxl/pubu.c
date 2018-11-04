// xtj
// by dubei

#include <ansi.h>
#include <room.h>

inherit ROOM;
//      int do_jump(string arg);
string pubu(object);

void create()
{
    set("short", BLU "�ٲ�"NOR);
    set("long", @LONG
ת��һ��ɽϿ��ˮ�����������ֻ��ɽ���һ��������Ƶ��ٲ�(pubu)
��к���£�����һ��Ϫ������ʤ�������ļ��쳣��ˮ��Ю����֦ʯ�飬ת��
�����ò�֪ȥ���Ĺ�ˮ�����ɣ�εΪ��ۡ�
LONG
    );

    set("outdoors", "xiangyang");
    set("item_desc", ([
        "pubu" : (: pubu :),
    ]));
    set("objects",([
               __DIR__"npc/diao" : 1,
                ]));
    set("exits", ([
        "southeast" : __DIR__"xiaolu2",
        "west" : __DIR__"xiaolu3",
    ]));

    setup();
 
}
void init()
{
	add_action("do_tiao", "tiao");
 
}
string pubu(object me)
{
     return "һ��������µ��ٲ���ˮ�����������˸о��ľ���ս��\n";
    }
int do_tiao(string arg)
{
	object me = this_player();

	if (me->is_busy()) return notify_fail("����æ���أ�\n");
        
      if( !arg || arg == "" || arg != "pubu" )
           return notify_fail("��Ҫ����������\n");

	if (me->query_dex() < 27)
		return notify_fail("����ͼ�����ٲ��У���¡¡��ˮ��ʹ�����е㷢��\n");

	if (me->query_skill("dodge") < 100)
		return notify_fail("����ͼ�����ٲ��У�ȴ�����Լ�Ŀǰ���Ṧ����ʵ�֡�\n");

        if (me->query_skill("force") < 110)
                return notify_fail("����ͼ�����ٲ��У�ȴ�����Լ��ڹ���Ϊ�ƺ���Ƿȱ���\n");

        if (!me->query_temp("yg_pbask")){
        message_vision("$N����������Ծ�����ٲ�֮�С���\n", me);
        write("���Ȼ�о�ˮ���������Լ��޷�������ˮ���򿹣���������ѹ����ҡ�һϡ�\n",me);
        message_vision(RED"ֻ��$N�絾��һ���ִ��ٲ��з��˳�����\n"NOR, me);
        me->set_temp("xth_hm",1);
        me->unconcious();
        return 1;
        }
	message_vision("$N����������Ծ�����ٲ�֮�У�ʹ�˸���ǧ��׹�������������̣�����վס��\n", me);
	me->move(__DIR__"pubu1");
	return 1;
}
