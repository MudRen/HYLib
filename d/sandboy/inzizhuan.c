// Room: /d/sandboy/inzizhuan
inherit ROOM;

void create()
{
  set ("short", "����");
  set ("long", @LONG
�������ڵķ��ã����з����й�����һ����¹������ı�����ˬˬ��
���µ�ˮĥש��Ĩ�õ�һ����Ⱦ��
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"zizhuan",
]));
  setup();
}
