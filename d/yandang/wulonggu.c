// Room: /d/yandang/wulonggu.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�������ڸ�ˬ����,�澰����,�ɳ�����,������Դ.�˹�λ��С����
֮��,�����Ϊ����.�����к�,�����ں�,��ˮ���¶˷���ֱ��,�γ���
��,���겻��.�Ӵ����¾���С������.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/yandang");
	set("exits", ([ /* sizeof() == 2 */
  "eastup" : __DIR__"tianzhu.c",
  "westdown" : __DIR__"xiaolongq.c",
]));

	setup();
	replace_program(ROOM);
}
