#include <ansi.h>
//inherit NPC;
inherit NPC;
int escape();
void create()
{
        set_name("����", ({ "crossoptilon","bird","chicken" }) );
        set("race", "Ұ��");
        set("age", 5);
        set("long", "һֻ��ɫ�Ĳ�����ͷ�������ɫ��ͷ�����������ܵĺ�ɫ�̵���״��ë����
��ʴ�״����ɫ���������̽���������š������ڵ��ϱı�������Ѱ��ʳ�\n");
        set("limbs", ({ "ͷ��", "����", "β��" }) );
        set("verbs", ({ "bite" }) );
        set_skill("move",3000);
        set("chaser",1);
        set("combat_exp", 300000);
        
        set("max_qi",1200);
        set("max_qi",600);
        set("max_jing",600);
        
        /*set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([
                100:    (: escape() :),
        ]) ); */
        
        set("chat_chance",1);
        set("chat_msg",({
                CYN"��������������������ؽ���������\n"NOR,
                "���������ų������������䵽�յص���һ�ߡ�\n",
        }) );   
        setup();
}  
/*int escape(){
        object ob,*env,room;
        int i;
        
        if (environment(this_object())->query("in_tree")) return 1;
        
        message_vision(CYN"\n"+name()+"�������ؾ����ţ��Ĵ��ų��������ԱߵĴ�����������������æ���ˡ�\n"NOR,this_object());
        env=all_inventory(environment(this_object()));
   for (i=0;i<sizeof(env);i++)
                if(userp(env[i])) env[i]->set_temp("zangbei/������",1);
        room=find_object(AREA_ZANGBEI"pine2");
        if (!objectp(room)) room=load_object(AREA_ZANGBEI"pine2");
        this_object()->move(room);
        return 1;       
}        

int follow_me(object ob, string dir)
{
        object env;
        string my_birth_place, to_go_place;
        
        if( !living(this_object()) || ob==this_object() ) return 0;
        
        env = environment(this_object());
        to_go_place = env->query("exits/"+dir);
        my_birth_place = file_name(this_object());
        if (domain_file(to_go_place)!= domain_file(file_name(this_object()))){
                return 0;
        }
        
        if( ob==leader
        ||      (query("chaser") && this_object()->is_killing(ob->query("id")))) {
                if( random(ob->query_skill("move")) > this_object()->query_skill("move") ) {
                        remove_call_out("follow_path");
                        call_out("follow_path", 1, dir);
                        return 1;
                }
                return follow_path(dir);
        }
}*/   
