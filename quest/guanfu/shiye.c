// /d/city/npc/shiye.c ֪��ʦү
 
// by dubei update 1997.7.4

#include <ansi.h> 
inherit NPC;
int ask_me(object who);
void create()
{
	set_name("����ˮ", ({ "wang huaishui", "wang" }));
	set("title", "֪��ʦү");
	set("gender", "����");
	set("age", 57);
        set("combat_exp", 30000);
        set_skill("unarmed", 50);
        set_skill("dodge", 60);
        set_temp("apply/attack",  20);
        set_temp("apply/defense", 20);
        set_temp("apply/damage",  20);
	set("shen", 0);
                set("inquiry", ([
                "ٺ»" : (: ask_me :),
        ]));
	setup();
        carry_object("/clone/misc/cloth")->wear();
}
int ask_me(object who)
{
        object me;
        int times;

        me = this_player();
        times = (int)me->query("gf_job",1);

        if (times<=20){
        command("say ��ûΪ��͢����ʲ����������Ҫٺ»��\n");
        return 1;
        }
        if((int)me->query("gf_gives")<(int)me->query("age")) {
        if (!me->query_temp("mark/huilu")  && times<2500){
        command("look " + me->query("id"));
        command("say �����������ȥ�ɣ�\n");
        who->add_money("gold",times/20);
        command("give "+me->query("id")+" gold");
        write(WHT"�����Ǯ����Ŀ���󲻴�԰���\n"NOR);
        me->set("gf_gives",(int)me->query("age"));
       return 1;
        }
         if (me->query_temp("mark/huilu")  && times<2500){
         command("hehe " + me->query("id"));
         message_vision("����ˮ��ͷ������˵������λ"+RANK_D->query_respect(me)+"�����ˣ��������Ĺ�ٺ��"
"�Ժ������������¡�\n",me);
        who->add_money("gold",10+times/10);
        command("give "+me->query("id")+" gold");
        me->delete_temp("mark/huilu");
        me->set("gf_gives",(int)me->query("age"));
        return 1;
        }
    }
        if (times>2500){
        command("say ���²����Ǹ�֪��ʦү�����ỹ�Ҹ�����ٺ»�أ�\n");
        command("flatter " + me->query("id"));
        return 1;
        }
        command("say û��ʱ���أ���ʲ��ٺ»��!\n");
        return 1;
}
int accept_object(object me, object obj)    
{
        int times;
        times=me->query("gf_job",1);

        if (!me->query("gf_job")){
        command("say ��Ե�޹��������¸�ң�\n");
        return 1;
        }
        if(obj->query("money_id")){
        if(obj->value() >= times*100){
        command("hehe "+me->query("id"));
        command("whisper "+me->query("id")+" ��ͷ��İɣ���ͷ�һ�úù�����ģ�");
        me->set_temp("mark/huilu",1);
        return 1;
        }
        else {  
               command("say ��ô��Ǯ�ܸ�ʲ�᣿��������ȥһ������Ժ���أ�");
        return 1;
              }
        }
        command("say �����"+obj->name()+"�����ң���ʲ���ã���");
        return 0;
}
void destroy (object obj)
{
        destruct(obj);
        return;
}
