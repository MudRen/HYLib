//Room: /d/japan/path.c
inherit ROOM;

void create()
{
   set ("short", "��·");
  set ("long", @LONG
һ�������Ļ��������Զ�����쿪ȥ������Ρ����񻧶���
�߸ߵ������ţ���������������Ѳ�ӡ����ֵ�������ͣ�Ĵ�����
LONG);

  set("exits", ([ /* sizeof() == 1 */
     "west" : __DIR__"dongmen",
      "east" : __DIR__"path1",
]));
  set("outdoors", "japan");
  setup();
        replace_program(ROOM);
}
