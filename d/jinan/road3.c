 // street2.c
#include <room.h>
inherit ROOM;
void create()
{
  set("short","б����");
  set("long",@LONG
�ƹ������������������У�����һ������ʯ��·��������ɣ��ʯ������
�ӿ����ݣ����Ծ��������������������ϻ�����һ�����������������·����
�����У�һƥ��������������������Զ���������಻�ϵ�ɽ�ͱ��Ƕ���̩
ɽ�ˡ�
LONG
  );
  set("exits",([
         "southwest":__DIR__"road2",
  "northeast" : __DIR__"road4",
               ]));
    set("outdoors", "jinan");
    set("coor/x",100);
    set("coor/y",2050);
        set("coor/z",0);
        setup(); 
}

