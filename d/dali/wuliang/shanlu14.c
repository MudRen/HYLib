// Modify By River 98/12
#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "б��");
	set("long", @LONG
�����Ǹ�б��,��С�����������,б�²������,�ɵ���ȥ�������������,
�����Ӳݴ���,ʮ�ֻ���,����ɢ�ż���Ǻ�.
LONG
	);
        set("outdoors", "����");

	set("exits", ([
           "south" : __DIR__"shanlu10",
           "north" : __DIR__"shanlu10",
           "west" : __DIR__"shanlu12",
           "east" : __DIR__"shanlu9",
	]));

	setup();

}

void init()
{    
       object me = this_player();
       if (random(me->query("kar")) <15 
        && me->query_skill("dodge",1) < 100){
          message_vision(HIR"�����Ǹ�б�£�$N��С�ģ������ϻ���������\n"NOR, me);
          }
       if((int)me->query_skill("dodge", 1) >= 20){
          me->receive_damage("qi", 35);
          me->receive_wound("qi",  35);
          }
       else{
          me->set_temp("last_damage_from", "��б�µ���");
          me->die();
          }
}
