#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "��϶");
        set("long", @LONG
������ʯ����ʯ��֮��ļз죬���߻谵�������Ըо������ܵ�ɳɳ
���Ǹ��ֶ������е�������һ�ɹ���ζ��Ҳ������һЩ�̱ǵ���Ϣ���㷢
��ǰ����һʯ��(shikuai) �������������Ĺ�â��
LONG);
        set("objects", ([
                    __DIR__"npc/yanjing1" : 1,
                    __DIR__"npc/hama" : 1,
        ]));
        set("exits", ([
              "east" : __DIR__"fengxi1",
              "out" : __DIR__"yuanzi4",
        ]));
         set("item_desc", ([                    
                "shikuai": HIW"\n���ʯͷ�����ɫ��ɢ��������ů����ʯ����һ�����ɫ��ϸ�ߣ�
ʯ���ϰ��ݽ�ȥ���Ǹ������������Ƶ������Ρ�\n"NOR,
        ]));
        setup(); 
}

void init()
{
        add_action("do_push", "tui");
        add_action("do_push", "push");      
}

int do_push(string arg)
{
        object me = this_player();
        if( !arg || arg=="" ) return 0;
        
        if( (int)me->is_busy() || me->is_fighting()) 
        	return notify_fail("����æ���ء�\n");
        	
        if( !me->query_temp("baituo_stone") ) return 0;
        if( (int)me->query_temp("baituo_stone") > 2) 
                return notify_fail("���Ѿ��ƶ�����ʯ�顣\n");
        if (arg == "shikuai" ){   
           	message_vision("$N�������˿��������˫�ְ�סʯ���ϵ���ӡ������������ȥ��\n", me);           
           	me->add_temp("baituo_stone", 1);
           	message_vision("$N��ʯ�鰴�´�������ԼԼ�������´���һ���¡����\n", me);            
        	me->start_busy(5);      
        	call_out("poisoned", 5, me);
        	return 1;
        }     
        return 0;
}

int poisoned()
{
        object me = this_player();
        if ((int)me->query_skill("poison", 1) < 120 && !me->query_skill("hamagong", 1)){
               tell_object(me, MAG "��е�����һ�����ǵ����ϸ���Ѿ�������������ϡ�\n" NOR );
               message_vision("$NͻȻ����һ�������������˶���\n", me);
               me->apply_condition("snake_poison", me->query_condition("snake_poison")+50);
               return 1;
               }   
        else {
               tell_object(me, MAG "��Ȼ�������һ�����ǵ����ϸ���Ѿ�����������ϡ�\n" NOR );
               tell_object(me, HIW "����æ�˹������������ĵ����ϸ�߱Ƴ��˴�롣\n" NOR );
               me->apply_condition("snake_poison", me->query_condition("snake_poison")+30);
               return 1;
               }
                
}
