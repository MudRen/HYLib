// hswz.c ��ʯΧ��
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "��ʯΧ��");
        set("long", @LONG
���������ʯΧ�ӵĵط���ʵ�Ǹ�ɽǰ��С����������ǳ�����֣�
�����������Ǵ�ɳĮ��һ���ȥ���������ɽ������ȴ�Ǵ��ԭ����Χ
���߰�����м��ٸ��Һ�ɫ�ľ�ʯ(stone)��������Ȼ�γɵ�����������
�����ġ�
LONG);
        set("resource/water", 1);
        set("exits", ([
            "southeast" : "/d/xingxiu/shamo4",
            "south" : "/d/xingxiu/shamo4",
            "north" : __DIR__"gebi2",
            "southwest" : __DIR__"caoyuan10",
        ]));                 
        set("item_desc", ([
                "stone" : "������һ���ر���ʯͷ�������滹�п�ʯ����
��������ʯ���ˣ�������������Щʲô������\n",
        ]));
        set("outdoors", "gaochang");
        setup();
}

void init()
{
        add_action("do_tui", "tui");
        add_action("do_tui", "push");
        add_action("do_kan", "read");
        add_action("do_kan", "look");
}

int do_tui(string arg)
{      
        object me, room;        
        me = this_player();
        room = this_object();       
        if( !arg ) return 0;              
        if( (int)room->query_temp("stone_pushed") ) 
                return notify_fail("����ô��ôϲ��û����ʯͷ��\n");         
        if (arg == "stone" ){        
         if (me->query_skill_mapped("force") != "hamashengong" ){
               me->add("neili", -1500);
               message_vision(HIR "$N�����������ʯһ�����������û�ƿ����������������Լ���\n" NOR, me);
               me->unconcious();
               return 1;
               }
         if (me->query("neili") < 1000 || me->query_str() < 25 ){
               message_vision("$N�����󡹦ʹ�������ƾ�ʯ����������������ֻ�����ա�\n", me);
               me->add("neili", -200);
               return 1;
               }        
      else{
             me->add("neili", -500);
               message_vision(HIG "$N���ڸ�󡹦������ת������һ�У�˫���Ƴ���\n
ֻ�����һ������ʯ��Ȼ��$N�ƿ��ˣ�¶���˺����ʯ����\n" NOR, me);
       if(me->query_skill("hamashengong", 1) < 100)
               me->improve_skill("hamashengong", me->query("int"));
               room->set_temp("stone_pushed", 1);
               call_out("stone_push", 10);
            }                    
       }
        return 1;
}

int do_kan(string arg)
{      
        object me, room;        
        me = this_player();
	room = this_object();      
        if( !arg ) return 0;               
        if( !(int)room->query_temp("stone_pushed") ) 
                return notify_fail("���ſ�ʯͷ��ô���ü���\n");                 
        if ( me->query_skill_mapped("force") != "hamashengong" )
                return notify_fail("�㿴�˰��죬���ǲ�����������д��Щʲô������\n");              
        tell_object(me, HIB "\n ������������
�˴��������ɽׯ֮�ص�������Ȼ�����ƿ���ʯ��
�������Ҹ�󡹦���ף��������ɽת֮�ˡ��ɰ�
����߷�����ɽׯ������\n    
            ����ɽׯׯ������ŷ����\n\n" NOR);  
        message_vision("$N����ʯ�����˰��죬����¶����ο�ı��飬����$N�Ų�ת�˼�ת���߽���ʯ���ﲻ���ˡ�\n", me);
        me->move("/d/baituo/midao");
        tell_object(me, "�㶵��תת���˰��죬�����Լ��Ѿ�����ɽ���С�\n");
        return 1;
}

int stone_push()
{
       object room = this_object();
       if(objectp(room)){
		message("vision", "���һ������ʯ�ֹ�������ס��ʯ����\n", this_object());
		room->delete_temp("stone_pushed");
         }
}
int valid_leave(object me, string dir)
{
       if( dir != "northwest" && !userp(me) && !me->query_temp("go"))
            return notify_fail("...\n");        
       return ::valid_leave(me,dir);
}
