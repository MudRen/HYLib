//rama@sz   
inherit NPC;  
inherit F_MASTER;  
        
//int ask_book();  
void check_azi();
void cp_npc(object ob,object me);
void use_poison();
int auto_kill();  
       
void create()  
{  
        set_name("��̹֮", ({ "you tanzhi", "you"}));  
        set("nickname", "����");  
        set("long",   
                      "����һ��������͹͹��һ��죬һ��ڣ����Ǵ��˺ۺۣ�\n"  
                      "������ã���ª�ɲ��Ѽ����޲���Ȼ��\n");  
        set("gender", "����");  
        set("age", 25);  
        set("attitude", "peaceful");  
//        set("shen_type", -1);  
        set("str", 35);  
        set("str", 35);  
        set("int", 20);  
        set("con", 30);  
        set("dex", 20);
        set("no_get", 1);
                              
        set("max_qi", 16500); 
        set("qi",16500); 
        set("max_jing", 14500); 
        set("jing",14500); 
        set("neili", 28000); 
        set("max_neili", 28000); 
        set("jingli",6000); 
        set("max_jingli",6000); 
        set("jiali", 250); 
        set("combat_exp", 6500000); 
        set("shen", -400000); 
        set("apply/armor", 90); 
        set("PKS", 1000000);  
                                             
        set_skill("force", 200);  
        set_skill("huagong-dafa", 320);  
        set_skill("dodge", 200);  
        set_skill("dodge", 200);  
        set_skill("strike", 200);  
        set_skill("claw", 200);  
        set_skill("sanyin-wugongzhao", 200);  
        set_skill("poison", 200);  
        set_skill("chousui-zhang", 200);  
        set_skill("parry", 200);  
        set_skill("tianshan-zhang", 200);  
        set_skill("feixing-shu", 200);  
              
        map_skill("force", "huagong-dafa");  
        map_skill("dodge", "zhaixinggong");  
        map_skill("strike", "chousui-zhang");  
        map_skill("parry", "chousui-zhang");  
        map_skill("claw", "sanyin-wugongzhao");  
        map_skill("sword", "tianshan-zhang");  
        map_skill("blade", "bingpo-blade");  
  set_skill("blade", 250);
set_skill("xuantian-strike", 380);
set_skill("bingpo-blade", 380);
        map_skill("blade", "bingpo-blade");  
	map_skill("strike", "xuantian-strike");
	map_skill("claw", "sanyin-wugongzhao");
map_skill("parry", "bingpo-blade");  
	prepare_skill("strike", "chousui-zhang");
	prepare_skill("claw", "sanyin-wugongzhao");            
        prepare_skill("strike", "chousui-duzhang");  
        prepare_skill("claw", "sanyin-wugongzhao");  
         set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "strike.zhaohuo" :),
                (: perform_action, "strike.biyan" :),
                (: perform_action, "strike.fushidu" :),
                (: perform_action, "strike.sandu" :),
                (: perform_action, "strike.huoqiang" :),
                (: perform_action, "strike.throw" :),
                (: perform_action, "strike.yinhuo" :),
                (: perform_action, "strike.zhaohuo" :),
                (: perform_action, "strike.huoqiu" :),
(: perform_action, "blade.kou" :),
(: perform_action, "blade.manakill" :),
(: perform_action, "whip.suo" :),
         }) );                  
	set("auto_perform",1);

 /*       set("inquiry", ([  
               "�׽" : (: ask_book :),
                                
                      ]));  
*/              
        setup();  
        carry_object("/clone/weapon/gangdao")->wield();  
        carry_object("/clone/cloth/cloth")->wear();  
}  
void init()
{
        if(this_player()->query_temp("azi/killer",1))
        {
                say("��̹֮���һ�����������"+RANK_D->query_rude(this_player())+"����Ȼ��ɱ�˰��Ϲ���Ҹ���ƴ�ˣ�����\n");
//                cp_npc(this_player(),this_object());
                //copy_status() 1.5*exp 1*neili 1*jingli
                kill_ob(this_player());
                set_leader(this_player());
                this_player()->fight_ob(this_object());
                return;
                     
        }

}

void check_azi() 
{      
        object ob,player;
        object me=this_player();
        object who=this_object();
        if( !interactive(me))
        return;
        ob=find_living("a zi");
  
        player=ob->query_temp("last_damage_from");
                if( objectp(player) ) 
                {
                if(ob=present("a zi",player) || ob=present("a zi"))
                {       
                        if((int)ob->query("qi")< (int)ob->query("max_qi")/2 )
                        {   
                                who->kill_ob(player);
                                player->fight_ob(who); 
                                tell_object(player,"��̹֮��ŭ������������Ѱ��Ϲ����˳���������ȥ���ɣ���\n");
                        }
                        else 
                        {
                                who->set_leader(player);
                                tell_object(player,"��̹֮�����е�������Ҫ�Ѱ��Ϲ����������ȥ����Ѱ��Ϲ��ﻹ���ң�����ɱ(kill)���ң�Ҫ��Ȼ�Ҿ��Բ���������Ѱ��Ϲ�����ߣ���\n");
                                call_out("auto_kill",10);
                        }
                }
                
                 
        }
        else  
        {
                tell_object(me,"��̹֮��������Ҫȥ�Ұ��Ϲ����\n");
                call_out("destruct_ob",1);
        }
       
}
int auto_kill()
{
        object me=this_player();
        object ob=this_object();
        ob->kill_ob(me);
        me->fight_ob(ob);
        remove_call_out("auto_kill");
}
 
void cp_npc(object ob,object me)
{
        mapping hp_status;
        hp_status = ob->query_entire_dbase();

        me->set("combat_exp", hp_status["combat_exp"]*(3/2));
        me->set("score",hp_status["score"]*(3/2));
        me->set("str", hp_status["str"]);
        me->set("int", hp_status["int"]);
        me->set("con", hp_status["con"]);
        me->set("dex", hp_status["dex"]);

        me->set("max_qi",    hp_status["max_qi"]*(3/2));
        me->set("eff_qi",    hp_status["eff_qi"]*(3/2));
        me->set("qi",        hp_status["qi"]*(3/2));
        me->set("max_jing",  hp_status["max_jing"]*(3/2));
        me->set("eff_jing",  hp_status["eff_jing"]*(3/2));
        me->set("jing",      hp_status["jing"]*(3/2));
        me->set("max_neili", hp_status["max_neili"]*(3/2));
        me->set("neili",     hp_status["neili"]*(3/2));
        me->set("jiali",     hp_status["jiali"]);
}

void die()
{
          
        object player,corpse,ob;
        player = this_object()->query_last_damage_from();
        if ( objectp( player ) ) 
        {
        message("vision","��̹֮��Ŀ����֮������ͻȻ����������Ѫ��
���Ͼ�Ȼ¶����һ˿�����Ц�ݣ������þ�����
���е����������ڻ����ĵ�����ȥ��\n",environment(player));
        message("vision","��̹֮���һ�������ˣ�\n",environment(player));

        tell_object(player,"����������̹֮��ʬ�壬�����ؿڴ��м�����������æ�������˳�����\n");
        ob=new("/d/xingxiu/obj/book.c");
        ob->set("my_owner",player);
        ob->move(player);
        tell_object(player,"����ϸһ��ԭ����һ���顣\n");
        if(!objectp(corpse = present("xiao feng",environment())) || !living(corpse) )
        {
                player->delete_temp("azi/killer2",1);
                player->delete_temp("azi/killer");
        }
        player->set_temp("you/done",1);
        }
        ::die();        
}

        
 
int accept_object(object me, object ob) 
{        
        if((string)ob->query("name")=="����"||(string)ob->query("id") == "a zi")    
        {
        if((int)ob->query("eff_qi") < (int)ob->query("max_qi")) 
        { 
                 ob->kill_ob(me);
                 ob->set_leader(me);
                 me->fight_ob(ob);
                return notify_fail("��Ѱ����˳�������ӣ���ȥ���ɣ�\n"); 
        }
        
        else {  
                        //give some bonus and return, you disappear 
                        tell_object(ob,"����̫лл��!\n"); 
                        } 
        } 
        else return notify_fail("����ʲô������ǲ�ң�");
                  
}

int accept_kill(object me)
{
        object who;
        if(!me->query_temp("azi/killer",1) && !me->query_temp("azi/killer2",1) )
        {
        command("say " + "�����а��֣������ߣ�\n");
        
        who=find_living("a zi");
                if(who)
                {
                        message("vision","��̹֮ץס���ϵĸ첲��һ�����Ҳ�Ƶ�ȥ�ˡ�\n",environment(me));
                        
                        me->delete_temp("azi/killer",1);
                        me->delete_temp("azi/killer2",1);
                        destruct(who);
                        call_out("destruct_ob",1);
                        return 0;
                        }
                
        }
        return 1;
}
int accept_fight(object me)
{
        if(!me->query_temp("azi/killer",1) || !me->query_temp("azi/killer2",1) )
        {
        tell_object(me,"��̹֮˵�������ҿ�û��˼�����棡��\n");
        return 0;
        }
        else
        {
        tell_object(me,"��̹֮ŭ��������Ȼ����ô����Ͷ̥���Ҿͳ�ȫ�㣡��\n");
        kill_ob(me);
        return 1;
        }
        return 1;
}
void destruct_ob(object me)
{

        me=this_object();
        destruct(me);
}


