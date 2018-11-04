// mg-room2.c �Թ�����
#include <ansi.h>
#include <command.h>
#include <room.h>
inherit ROOM;

void create()
{
        set("short", CYN "�Թ�����" NOR);
        set("long", "��һ�������й��Ķ��Ǻ��������м�һ�����ˣ�����д����
"HIY"�������ʥ��ʦ����λ��"NOR"�����Ҹ�����ʮ�ˣ�д�����ջء�������
·�������ӹ����������ġ��������š������֡�����������������
������\n");
        set("no_sleep_room", 1);
        set("exits", ([
              "south" : __DIR__"mg-room1",                     
        ]));
        setup(); 
        set("tie_count", 1);
}

void init()
{
       this_player()->set_temp("ketou_times", 50);
       add_action("do_ketou", "ketou");
}

int do_ketou()
{
       int i;
       object me, ob, *inv;
       me = this_player();               
       if(me->query_temp("ketou_times") == 0 ){        
         me->set_temp("ketou_times", 50);
         message_vision("ͻȻһ�Ű�ɫ���´Ӻڰ���Ѹ���쳣�ĳ������嵽��$NԼĪһ��֮�����͵�
ֱ������������ȥ��ϡ�Ǹ����Σ����ӳ���£�ֻ������������ɫ���ۣ�
����������Ѫ��������Ҳ��Ѫ�����죬���θߴ�֮�������ٱȳ��˸�����ߡ�
��ҹ�������ֲ��ޱȡ��ǹ�ֶ�Ȼ��˫��ǰ�죬ʮ��ָ�ױ���ָ����������
Ҳ������Ѫ��\n", me);
         message_vision(HIB"�ǹ�������Ц�����������������Թ�����ס��һǧ�꣬����˭�����ţ�
˭�����������󵨣����ǹ������ת��˫�ֶ���$N���е���������������\n"NOR, me);
         me->start_busy(2);
         if(random(10)>5){
            tell_object(me, HIR "��о���֫һ�飬���ã�\n" NOR );
            tell_room(environment(me), HIR +"ֻ��"+me->name()+"˫ϥ�򵹣�Ȼ����°�Į���������ˣ�\n" NOR, ({ me }));    
            inv = all_inventory(me);
            for (i = 0; i < sizeof(inv); i++){
               if(inv[i]->query("armor_type")=="married") continue;
               destruct(inv[i]);
               }
            me->unconcious();
            message_vision("�������ֻع�������ץ��$N���۶�ȥ��Ƭ�̼��ߵ���Ӱ���٣�\n", me);            
            me->move(__DIR__"shulin1");
            return 1;
            }
         tell_object(me, HIR "������һ�����������Ծ����Զ��\n" NOR );
         message_vision("�������ֻع����������۶�ȥ��Ƭ�̼��ߵ���Ӱ���٣�\n", me);            
       }

       me->add_temp("ketou_times", -1);        

       message_vision("$N���������ڿ�����ǰ����һ��ͷ��\n", me);

       if ( random(100) == 30 
       && !present("kuaixueshiqing tie", me)
       && query("tie_count") >= 1){
          add("tie_count", -1);
          ob=new(__DIR__"obj/tie")->move(environment(me));
          message_vision("ͻȻž��һ������һ��ֽ������$N����ǰ��\n", me);
       }       
       return 1;
}
int valid_leave(object me, string dir)
{
       me->delete_temp("ketou_times");
       return ::valid_leave();
} 

int count = 1;
void reset()
{
    if (--count == 0) {count = 40; set("tie_count", 1); ::reset();}
}

