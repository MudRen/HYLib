// Room: /d/hainan/midao.c

inherit ROOM;

void create()
{
	set("short", "�ܵ�");
	set("long", @LONG
ɽ���е�һ���ܵ�,ʮ�ֶ���,һ·�ϵ���ʯ�����׻����·�,�����
����Զ,�ڶ����Ͼ���һ������,����ͨ��,���Բ����Եĺڰ�.����Щɽ��
�ϻ���Щ����,����ʵ�ڿ�������Щʲô!
LONG
	);
	set("no_clean_up", 0);
	set("item_desc", ([ /* sizeof() == 2 */
  "����" : "һ����ֵĻ���,�������,������ʹ�˷���.
",
  "ɽ��" : "ɽ���ϻ���һЩ����.
",
]));
	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"midao1",
  "westdown" : __DIR__"xuanya",
]));

	setup();
	replace_program(ROOM);
}
