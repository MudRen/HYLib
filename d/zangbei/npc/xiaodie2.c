#include <ansi.h>
inherit NPC;
int check_other(object me); 
void create()
{
        set_name("С��",({"xiao die","xiaodie"}));
        set("long","
С�������÷·����Ժ�ˮ����������������۾���Ȼ�ڱ����п���������ô
���������������ȴ������ˮ���������ʺ�Ķ�������ˮ��Ʈ������ڵ�ͷ
���ڷ��з��裬�������۾��У�������˵������������ͬ�顣\n");
        
        set("gender","Ů��");
                
        set("age",20);          
        set("int",52);
        set("per",100);
        set("cps",20);
        set("str",10);
        
        set("combat_exp",10000);  
        set("attitude", "friendly");
        
        
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([ 
        ]) );           
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
     
        }) );
        set("chat_chance",1);
        set("chat_msg",({
                "С�������ʵ�����ֻ���㣬����û�У���\n",
                "С���������һ���������û�л������ô��������\n",
                
        }) );                   
        
        setup();
        carry_object(__DIR__"obj/redcloak")->wear();
    
}  
void init()
{       
        object me;
        ::init();
        if( interactive(me = this_player()) && !is_fighting() ) {
                if (!me->query("zangbei/����¥") && !me->query("zangbei/������") && !me->query("zangbei/ɱ����"))
                        return;
                remove_call_out("greeting");
                call_out("greeting", 1, me);
        } 
} 
void greeting(object me)
{
        object ob;
        ob=this_object();
        if( !me || environment(me) != environment() ) return;
        if (me->query("zangbei/����¥")) {
                message_vision("С����$N�����һЦ������$N���\n",me);
                return;
        }
        if (me->query("zangbei/������")) {
                message_vision("С��ҧ���촽������������$N����$N�������֣�ת����������ȥ��\n",me);
                me->set("zangbei/����¥",1);
                tell_object(me,"͸������������Լ������Զ����һ��С��¥��\n");
                destruct(this_object());
                return;
        }
        if (me->query("zangbei/ɱ����")) {
                message_vision("С�����ĵ�˵�����㣬�ѵ����Ҫȥɱ�ҵ������ѵ���Ͳ�Ҫ���ǵ�δ����ô����\n",me);
                return;
        }
        
        
}  
