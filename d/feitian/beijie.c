// Room: /d/feitian/beijie
inherit ROOM;

void create()
{
  set ("short", "����");
  set ("long", @LONG
���ߵ����֣����������ŵ���һ��ŨŨ��ţ�����������̲�סʹ����������
�ֵ������һ��ţ��ݣ��ھ������Ƿǳ������ģ�������Ǿ����㳡�ˡ�
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"niurouguan",
  "north" : __DIR__"jingbeisu",
  "south" : __DIR__"guangchang",
]));
  set("outdoors", "feitian");
  setup();
  replace_program(ROOM);
}
