// Room: /d/yandang/shanlu.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������ȫ���İ�����,�ֱ���ͻ����,Ӧ������,�羰�续.���ֵ�
�ϲ�,��һɽ��(dong),������һ����������,�бǿ��´�,�׳������.
�����,����������ı��δ��������ڼ�,��Ϊ'�屮��'.
LONG
	);
	set("no_clean_up", 0);
	set("item_desc", ([ /* sizeof() == 1 */
  "dong" : "���򶫿���,״���ư,�������.������Ȫ�Ӷ�������,��'��
��Ȫ',�����ɰ����辰ɫ����.
",
]));
	set("outdoors", "/d/yandang");
	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"shanlu2",
  "eastdown" : __DIR__"shanxia",
]));

	setup();
	replace_program(ROOM);
}
