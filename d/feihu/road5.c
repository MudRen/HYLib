// ѩ·
// by steel 

inherit ROOM;
void create()
{
	set("short", "ѩ��ǰ");
	set("long", @LONG
	·�����������ʧ��,������һ��Сɽ��,��Լ��ȥ,�ƺ��и�ɽ����   
LONG
	);
	
        set("exits", ([
		"southeast" : __DIR__"road2",
		"northwest" : __DIR__"hole1",
	]));
set("no_npc",1);
	setup();
     //   replace_program(ROOM);
}

int valid_leave(object me, string dir)
{

       if(dir=="northwest")
      {	
       if( (int)me->query("combat_exp")<50000)
         {
         tell_object(me,"�㻹�Ǳ�ȥ������!\n");
         return 0;
          }
       }
        return ::valid_leave(me, dir);
}
