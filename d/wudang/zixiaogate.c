//Room: zixiaogonggate.c ����������
//Date: Sep 22 1997

inherit ROOM;

void create()
{
      set("short","����������");
      set("long",@LONG
�����ߵ���չ����£�ǰ������䵱ɽ��Ϊ���Ĺ����������ˡ�
������ɽ�������ߵʹ������¡���Χ��ľɭɭ��������֣���ɫ����
���������䵱ʦͽ����Ҫ�������
LONG);
      set("exits",([ /* sizeof() == 1 */
          "northdown"  : __DIR__"shijie2",
          "southup"    : __DIR__"guangchang",
          "west"    : __DIR__"zixiao",
          "south"    : __DIR__"zixiao2",	
          "westdown" : __DIR__"shanlu",
"eastdown" : "/d/jingzhou/shanmen",

      ]));
      set("outdoors", "wudang");
      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}
