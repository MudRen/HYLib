 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <room.h>
inherit ROOM;
void create()
{
  set("short","˴��ɽׯ");
  set("long",@LONG
����Ǻպ�������˴��ɽׯ��˴��ɽ�ֳ���ɽ����˵��˴�����ػ��ĳ���ء�
�����Ǽ��Ѳ��ö�֪��������ķ���ȷʵǧ���������ڴ���һ�������������
һ�����Ρ���ؤ����������֮�£���ʵ�Ǹ������¡�
LONG
  );
  set("exits",([
         "east":__DIR__"street2",
                 "north":__DIR__"private",
               ]));

        set("valid_startroom", 1);
        set("coor/x",10);
        set("coor/y",1950);
        set("coor/z",0);
        setup();
        create_door("north", "�ϵ���", "south", DOOR_CLOSED);
}
int valid_leave(object me, string dir)
{
        object ob;
        if( dir == "north" && ob=present("master nangong", this_object()))
                return notify_fail("��������·��"+ob->name()+"��ס�� ��\n");
        if( dir == "north" && !query("exits/north"))
                return notify_fail("������Ȱ��ϵ��Ŵ򿪣�\n");
        return 1;
}      
