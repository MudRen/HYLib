#include <ansi.h>
inherit F_VENDOR;
inherit NPC;
void mimicurse();
int do_answer1();
void create()
        {
        set_name("Ϲ�Ӱ���", ({ "xiazi aming","aming" }) );
        set("title",HIR"������"NOR);
        set("gender", "����" );
        set("age", 25);
        set("class","yinshi");
        set("attitude", "friendly");
        set("long","��ɫ�԰ף����۷��ף���˵�Ǽ��ϸ�һ��������������ʿ��\n");
        set("combat_exp", 3500000);
        set("reward_npc", 1);
        set("difficulty", 5);
        
        set("int",70);
        set("fle",40);
        set("cps",60);
        
        set("force", 1000);
        set("max_force",1000);
        set("force_factor", 40);
        set("mana", 500);
        set("max_mana", 500);
        
        

          
        set_skill("move", 200);
        set_skill("force", 200);
        set_skill("spells", 150);
        set_skill("unarmed", 150);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("magic",150);     
        set_skill("bloodystrike", 160);
        set_skill("iron-cloth",150);
        
    
    set("inquiry", ([
           "��ʦ����" : (: do_answer1 :), 
        ]) );
        
    set("chat_chance", 2);
    set("chat_msg", ({
            "Ϲ�Ӱ�����̾��һ����������һƬ�հף�ʲô���㲻����������\n",
            "Ϲ�Ӱ���Ц��˵��������II����õģ����Ұ�����II������\n",
            "Ϲ�Ӱ����޺�˵�����Ǹ����ֶ��٣�ÿ���������Ҹ����������������Ƶġ�����\n",
            "Ϲ�Ӱ������ص�˵������֪���Լ���ʦ������\n",
           "Ϲ�Ӱ���������������֪������II�ļ��������𣿱�֤���ʣ�����һ�������߲��ɲ�����������\n"
        }) );
        setup();
        carry_object("/clone/misc/cloth")->wear();
     
        
} 
void init()
{       
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) 
        {       remove_call_out("greeting");
                call_out("greeting", 1, ob);    
   }        
} 
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
     say( "Ϲ�Ӱ�����"+ob->query("name")+"΢Ц������λ" + RANK_D->query_respect(ob)
                                + "������üֱ��ͦ��һ����֪���Ǵ󸻴��֮�ࡣ\n"); 
} 
int do_answer1()
{
        int betray;     
        string respect; 
        if(!this_player()->query_temp("money_given") )
        {
    say("Ϲ�Ӱ�����Ц��������������Ǻǡ������������ǵú���������������������ˮ�����ء�������\nϹ�Ӱ��������һֻ��ָ������һ�Ρ�\n");
        return 1;
        }
        betray=this_player()->query("betrayer");
        respect=RANK_D->query_respect(this_player());
        if(!betray)
                {
                command("admire "+this_player()->name());
       say("Ϲ�Ӱ��������˵����������ͷ�����Ĳ��ţ���"+respect+"��ôרһ���������ѵ�ѽ����\n����ض����ꡣ����\n");
                }
        else if(betray==1)
                {
                command("admire "+this_player()->name());
        say("Ϲ�Ӱ����������������ͷ�����Ĳ��ţ���"+respect+"����ֻ����һ�����ɵ���Ҳ��\n�ѵ��ˡ�������ض����ꡣ����\n");
                }
                
        else if(betray<6)
                {
                command("pat "+this_player()->name());
         say("Ϲ�Ӱ����ֺõ�������Ų������Ų�"+respect+"��Ȼ��ʶ��������Ȼ����"+chinese_number(betray)+"�����ɣ�\n���ض����˺ܶ�ε����������ձ��ܳɾʹ�ҵ����\n");
                }
        else
                {
                command("?");
                say("��ϰ��ʦ��æ���ҵİ�����ָ������\n");
                command("faint "+this_player()->name());
        say("Ϲ�Ӱ�������һ̯���ƣ���������ʵ�������������������\n");
                command("cry");
                }
        this_player()->delete_temp("money_given");
        return 1; 
}
          
int accept_object(object who, object ob)
{
        if(ob->name()=="�ƽ�")
        {
    say("Ϲ�Ӱ�������˵��������ô�С�������������ȴ�������Żƽ�����"+this_player()->name()+"�û�ȥ�����ӡ�\n");
        this_player()->add_temp("money_given",1);
        return 1;
        }
        
    return notify_fail("Ϲ�Ӱ���ڨЦ������������ã�ֻ��ˡ�ѽ����ˡ�����\n");
}  
