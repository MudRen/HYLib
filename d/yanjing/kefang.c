// Room: /d/yanjing/kefang
inherit ROOM;

void create()
{
  set ("short", "�ͷ�");
  set ("long", @LONG
һ�����ӿ��Ŵ���,һ���Ȼ���שͷ����,���ϵ������Ǵ��鲼����,��
�˼�������,�߽ŵĵط��������,�ݽǵĵ����л���һЩˮ,һ�����ŵ�ζ��
Ѭ����ֻ���ܳ�ȥ.
LONG);

        set("hotel",1);
	set("no_clean_up", 0);
set("sleep_room",1);
  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"tianjin",
]));
  setup();
}

int valid_leave(object me, string dir)
{
	if ( dir == "east" ) me->delete_temp("rent_paid");

	return ::valid_leave(me, dir);
}

