// Room: /d/hainan/midao2.c

inherit ROOM;

void create()
{
	set("short", "�ܵ�");
	set("long", @LONG
ɽ���е�һ���ܵ�,ʮ�ֶ���,�����ߵ�ɽ����ʱ���ܿ���һЩ��ӡ.
��֪����˭����������Ӳ��ʯͷ�Ͽ�����ӡ,��ʮ�־���.��ɽ����һͷ
��һ��������״��ʯͷ,����ʮ�ֹ⻬.
LONG
	);
	set("no_clean_up", 0);
	set("item_desc", ([ /* sizeof() == 1 */
  "ʯͷ" : "����һ��������״��ɽʯ,���ھ������˰ᶯ��ԭ��,�Ե�ʮ��
�⻬,�����ܵ�ɽʯ�ܲ�һ��,��֪�����ܲ��ܰᶯ��(push stone).
",
]));
	set("exits", ([ /* sizeof() == 2 */
  "out" : __DIR__"cave5",
  "southdown" : __DIR__"midao1",
]));

	setup();
	replace_program(ROOM);
}
