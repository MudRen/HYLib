// /d/xingxiu/silk3.c
inherit ROOM;
#include <ansi.h>

int wind = 0;

void create()
{
        set("short", YEL"��ɳɽ"NOR);
        set("long", @LONG
��ɽ����ʮ�ף�ɽ�嶸�ͣ����絶�С���´������Ȫ����ɽ���ɳ����
������Ȫ��������ɽ���»�ɳ����������׹�����������ڶ�����ζ��Ȼ��
�ʳơ�ɳ����������
LONG);
        set("outdoors", "yili");

        set("exits", ([
                "south" : __DIR__"silk3",
                "west" : __DIR__"silk3b",
        ]));

        setup();
        set("yushi_count", 2);
}

void do_move(object me)
{
        if(!me) return;
        tell_object(me, HIR"��һ���������ŭ�ķ籩�У��������ɼ���ֻ������������....\n\n"NOR);
        me->unconcious();
        me->move(random(2)?"/d/xingxiu/silk3b":"/d/xingxiu/silk3");
        message("vision", "ͻȻһ����ι�����һ��"+me->name()+"˦�˹�����\n",environment(me), ({me}));
}

void init()
{
   if(this_player()->query_temp("xlz/hang") && wind == 0)      
//           call_out("do_wait", 3+random(10), this_player());
           call_out("do_wait", 300+random(100), this_player());
   else if(wind > 0) 
           do_move(this_player());
   
   add_action("do_kangheng", "kangheng");
   
}

#include "/kungfu/skill/eff_msg.h";

int do_kangheng()
{
        
        object me;
        int p;
        
        me = this_player(); 
        
        if(wind <= 0 || !me->query_temp("xlz/hang")) return 0;
        
        if( me->query_temp("weapon") )
                return notify_fail("������Σ�յ�����£��㻹��������е���������\n");
                
        if (me->query_skill_mapped("unarmed") != "xianglong-zhang"
        || me->query_skill_mapped("parry") != "xianglong-zhang")
                return notify_fail("�����ǽ��첻Ӧ�����ز����ʱ����Ψһ�ĳ�·���á�����ʮ�����ơ����⣡\n");  
                
        if( (int)me->query("max_neili") < 3000)
                return notify_fail(HIR"\n�����ڲŷ����Լ���������Ϊ����˵�ǳ��������... ���ں���Ѿ�����...\n\n"NOR);      

        if( (int)me->query("neili") < 500 )
                return notify_fail(HIR"������Լ��Ѿ����������̣�˫���ڷ���Ҳ�ڲ�ס�ز�����\n"NOR);
                
        tell_room(me, HIC"��ҧ�����أ�˫�ƻ�������Ĭ���ʮ���ƵĿھ�����ͼ������ص�ŭ����ά���Լ�����С������\n"NOR); 
        
        me->receive_damage("qi", me->query_con()*10);
        me->add("neili", -500);
        p = (int)me->query("qi")*100/(int)me->query("max_qi");
        message_vision("( $N"+eff_status_msg(p)+" )\n", me);
        me->add("combat_exp", 100); 
        me->add_temp("xlz/hang", 1);      
        return 1;
}


int do_wait(object me)
{
        
        object *obj, ob = this_object();
        int i;
        
        if(!me || environment(me) != ob
        || !living(me) || me->is_fighting()) 
                return 0;
        
        tell_room(ob, HIY"
ͻȻ��һ������ķ����������Ǽ�����Х���絶���罣��Խ��Խ��... Խ��Խ��...

˲�䣬�Ѿ��ǿ�����������Ļ�ɳ���������һ�˽���һ�ˣ�һ������һ��...

�������ɳ������һֻ����Ư����С�ۣ�������뱻����Ȼ����û��ֻ�з����

���࿹��(kangheng)�ˣ�\n" NOR);  

        ob->set_temp("apply/long", YEL"�����ɳ���죬����Х���Ǽ�����Х���絶���罣��Խ��Խ��... Խ��Խ��...\n"YEL);
        ob->delete("exits");
        obj = all_inventory(ob);
        if(obj)
                for(i=0; i<sizeof(obj); i++) {
                        if(obj[i]->query_temp("xlz/hang")) continue;
                        do_move(obj[i]);
                }

        
        wind = 15;
        me->start_busy(10);
        call_out("do_wait2", 10+random(10), me);        
        return 1;
}

int do_wait2(object me)
{
        
        object *obj, ob = this_object();
        int i, p;
        string msg;
        
        if(!me || !userp(me) || environment(me) != ob || me->is_ghost() ){
                remove_call_out("do_over"); 
                call_out("do_over", 5, ob);
                return 0;
        }
        
        if( wind <= 0) {
        	remove_call_out("do_over"); 
                call_out("do_over", 5, me);
                return 0;
        }
        
        wind--;
        
        me->start_busy(10);
        
        if(!living(me)){
                me->delete_temp("xlz/hang");
                me->set_temp("last_damage_from", "����ɳ��û������");
                me->die();
                return 0;
                }
                
        switch(wind){
                case 0: remove_call_out("do_over"); 
                        call_out("do_over", 5, me);
                        return 0;
                case 14: msg = YEL"\n��ɳԽ��Խ��Խ��Խ��... \n\n"NOR; break;
                case 11: msg = YEL"\n��ɱ��ͬ����һ�㣬һ�˽�һ�˹��������������ö������ᣡ\n\n"NOR; break;
                case 8: msg = YEL"\n���𽥱����ˣ���ǿ�ҵ���������������ת�ţ������ǵ��˱���������ˣ�\n\n"NOR; break;
                case 4: msg = YEL"\n����������Ȼ���ˣ�����ǿ�ҵ�����ȴ���ϵؽ���ѹ�ȣ���ǰ��һƬ��ɳ��ʲôҲ��������\n\n"NOR; break;
                case 1: msg = YEL"\n��Խ��Խ���ˣ�����Ļ�ɳҲ������ʧ�������ִ�͸�˹���... \n\n"NOR; break;
                default: msg = random(2)? YEL"\n������ش��ţ������ɰ�����������ϣ���ʹ��֣�\n\n"NOR:
                                          YEL"\nǿ�ҵ����������ܺ�Х�ţ�����Ѿ���Ϊһ�壬����û���˶���������\n\n"NOR; break;
                }
        tell_room(ob, msg);  

        obj = all_inventory(ob);
        if(obj)
                for(i=0; i<sizeof(obj); i++) {
                        if(obj[i]->query_temp("xlz/hang")) continue;
                        do_move(obj[i]);
                }

        me->receive_damage("qi", 200+random(500));
        p = (int)me->query("qi")*100/(int)me->query("max_qi");
        message_vision("( $N"+eff_status_msg(p)+" )\n", me);
        
        call_out("do_wait2", 10+random(10), me);         
        return 1;
}

int do_over(object me)
{

        wind = 0;
        tell_room(this_object(), HIW"\nͻȻ�䣬��罥��Զȥ����ջ�Ȼ���ʣ�һ���ָֻ���ԭ�������ӣ���ɳ����ɽ...\n\n"NOR); 
        
        this_object()->set_temp("apply/long");
        this_object()->set("exits", ([
                "south" : __DIR__"silk3",
                "west" : __DIR__"silk3b",          
                ]));  
                
        if(!me || !userp(me) || environment(me) != this_object()
        || !living(me) || me->is_ghost())
                return 0;
                
        me->start_busy(2);
        if((int)me->query_temp("xlz/hang") > 1){
                me->set("xlz/hang", 1);
                me->delete_temp("xlz/hang");
                tell_object(me, GRN"�㾭��һ���භ���Ѿ�ȫ�����ѣ�����ӷ������õ�����ʾȴʹ����Լ��Ľ���ʮ���Ƹ������ģ�\n"NOR);
                tell_object(me, HIC"�������˽���ʮ����֮���裡�Լ�������Ҳ�õ��˸��ƣ�\n"NOR);
                me->add("con", 1);
                me->add("str", 1); 
                }      
        return 1;
}
