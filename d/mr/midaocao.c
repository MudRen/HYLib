//midao.c
inherit ROOM;

void create()
{
  set("short","�ܵ�");
  set("long","��������ڵ��ܵ�������Ļ�ݵ���Ϊ������ֱ����ԭ������ġ�\n"); 
  set("exits" , ([
    "north" : "/d/city/kedian",
    "south" : "/d/mr/yanziwu",
      ]));
  set("no_npc", 1);
  set("no_clean_up", 0);
 setup();
}
