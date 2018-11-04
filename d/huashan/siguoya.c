// siguoya.c
// Dec.11 1997 by Venus
inherit ROOM;
void quarter_pass();
void create()
{
        set("short", "˼����");
        set("long", @LONG
���ǻ�ɽ��˼���¡�Σ�����и�ɽ�����ǻ�ɽ���������ӷ��������
�ܷ�֮�������Ϲ�ͺͺ�Ĵ�ݲ���������һ����ľ����Σ�����������ഫ
����Ů�����ϵ�һ�����飬���껪ɽ�ɵ���ʦ�Դ�Σ��Ϊ�ͷ�����֮����
��Ҫ�Ǵ˴��޲���ľ���޳������ܷ��ĵ��������˼��֮ʱ������Ϊ��
�����ţ��������͡�
LONG );
        set("exits", ([ /* sizeof() == 2 */
                "northdown" : __DIR__"yunupath2",
                "enter"     : __DIR__"sgyhole1",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "huashan" );
        setup();
	quarter_pass();
}
 
void init()
{
        object me = this_player();
        if (me->query_temp("xunshan")) me->set_temp("xunshan/siguo", 1);
        return;
}
void quarter_pass()
{
	mixed *local;

	local = localtime(time() * 60);
	if (local[2] < 6 || local[2] >= 21) {
		set("long", @LONG
���ǻ�ɽ��˼���¡�Σ�����и�ɽ�����ǻ�ɽ���������ӷ���������ܷ�
֮�������Ϲ�ͺͺ�Ĵ�ݲ���������һ����ľ����ɫ�Ұ������ѿ��������ܵ�
���
LONG
		);
		delete("exits/zuan");
	}
	else {
		set("long", @LONG
���ǻ�ɽ��˼���¡�Σ�����и�ɽ�����ǻ�ɽ���������ӷ���������ܷ�
֮�������Ϲ�ͺͺ�Ĵ�ݲ���������һ����ľ����Σ�����������ഫ����Ů��
���ϵ�һ�����飬���껪ɽ�ɵ���ʦ�Դ�Σ��Ϊ�ͷ�����֮������Ҫ�Ǳ��һ
���޲���ľ���޳������ܷ��ĵ��������˼��֮ʱ������Ϊ�������ţ�����
���͡�
LONG
		);
		set("exits/zuan", __DIR__"hole");
	}
	call_out("quarter_pass", 30);
}

int valid_leave(object me, string dir)
{
  if (me->query("fengset") && dir=="zuan" && random(10) > 7)
	{
	me->move(__DIR__"luoyan");
	return notify_fail("��ѭ�Ÿ��ٵĽݾ�һ���ӽ����˼�ɽ�ڡ�\n");
	}
	return ::valid_leave(me, dir);
}
