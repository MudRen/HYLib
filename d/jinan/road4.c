 // street2.c
#include <room.h>
inherit ROOM;
void create()
{
  set("short","����");
  set("long",@LONG
̩ɽ������ǰ�ˣ������������������ǵ����·�����������������ʯ
���������۵ĵ���һ������ߵ�ͭ���������˵�ǵ������������̩ɽ����
����������ī���͵ġ���������ǧ��������
LONG
  );
  set("exits",([
         "southwest":__DIR__"road3",
         "northeast":"/d/taishan/daizong",
               ]));
    set("outdoors", "jinan");
    set("coor/x",300);
    set("coor/y",2200);
        set("coor/z",0);
        setup();
    replace_program(ROOM); 
}     
