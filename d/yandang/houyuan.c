// Room: /d/yandang/houyuan.c

inherit ROOM;

void create()
{
	set("short", "��Ժ");
	set("long", @LONG
�ӻ��̵ĺ�Ժ�ﻹ��ͣ�ż�������,����С�����æ��ж����,��
���մ���ؽ���һ����,Ժ�еĴ�����˩�ż�ͷ¿,�����������̧
��ͷ����,������,���Ǳ�����˼�,��ȥ��!
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"cahuopu",
]));
	set("outdoors", "/d/yandang");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
