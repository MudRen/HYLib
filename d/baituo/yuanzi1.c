#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "Ժ��");
        set("long", @LONG
���Ժ������ֻ�м���С����ȴ�ѷ����ϰٶѵ�ʯͷ����Щʯͷ�д�
��С������һ�䷿�ݣ�С��һ��Ѽ�����㷢���Ա߰�ǽ����һ�������
��ˮ��ӯӯ��������ʲô����������е�����(tiemen)�������Ѿ������ˡ�
һ�ɹɵ��ȳ�ζƮ����ʹ���Ҫ��Ż�ˡ�
LONG);
        set("exits", ([
              "northwest" : __DIR__"yuanzi2",
              "jumpdown" : __DIR__"shetan",
        ]));
        set("outdoors", "����ɽ");
        setup(); 
}

void init()
{
     	object me = this_player();
      	if(me->query_skill("poison", 1) < 50)
      		me->apply_condition("snake_poison", me->query_condition("snake_poison") + 5);
        add_action("do_fan", "fan");
        add_action("do_fan", "pa");
        add_action("do_fan", "climb");
        add_action("do_push", "push");
        add_action("do_push", "tui");
        add_action("do_push", "strike");                  
}

int do_fan(string arg)
{
        int dex;
        object me = this_player();

        dex = me->query_dex();

        if (me->is_busy() || me->is_fighting() )
        	return notify_fail("����æ���ء�\n");
        	
       	if (dex < 18 )
        	return notify_fail("�Ⱛǽ�䰫����ȴ��ôҲ������ȥ��\n");
       	if (dex > 17 ){  
           	message_vision("$N˫���ڰ�ǽ��һ����һ��������˹�ȥ��\n", me);
           	me->move(__DIR__"yuanzi");
           	message("vision", me->name() + "��Ժ�����淭�˹�����\n",environment(me), ({me}) );
           	return 1;
           	}     
}

int do_push(string arg)
{
        int str;
        object me = this_player();
        str = me->query_str();

       	if( !arg ) return 0;
       	if (arg == "tiemen" ){        
       		if( (int)me->query_skill("hamagong", 1)){
           		message_vision("$N�������ӣ�˫��ƽ���������š�\n", me);
           		message_vision("����ͻȻ�򿪣�$Nһû������˽�ȥ������ȴ�ֺ����ˡ�\n", me);
//           		me->receive_damage("neili", 100);
           		me->receive_damage("jing", 50);
           		me->move(__DIR__"yuanzi");
           		message("vision", "ֻ��ž��һ����һ����Ӱ�����ų����˹�����\n",environment(me), ({me}));
           		}
       		if (str < 21 )
               		return notify_fail("��ʹ���˳��̵��������ɾ����Ʋ��������š�\n");
      		else {  	
           		message_vision("$Nʹ��ȫ�������������ţ�������ȴ��˿������\n", me);
//			me->receive_damage("neili", 300);
           		me->receive_damage("jing", 150);
           		}       
       		}
       return 1;        
}