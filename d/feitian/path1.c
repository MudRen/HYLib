//Room: /d/feitian/path1.c
inherit ROOM;

void create()
{
   set ("short", "��·");
  set ("long", @LONG
һ�������Ļ��������Զ�����쿪ȥ�����߾�����ʷ�Ŷ�����
Ρ������Ÿ߸ߵ������ţ���������������Ѳ�ӡ����ֵ�����
��ͣ�Ĵ�����
LONG);

  set("exits", ([ /* sizeof() == 1 */
     "south" : "d/japan/senlin2",
      "southeast" : __DIR__"path2",
]));
  set("outdoors", "/d/japan");
  setup();
        replace_program(ROOM);
}
