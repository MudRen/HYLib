// /u/beyond/mr/npc/yan.c
// this is made by beyond
// update 1997.7.1
#include <ansi.h>
int give_tools();
inherit NPC;

void create()
{
        set_name("������", ({ "yan mama", "mam", "yan" }));
        set("gender", "Ů��");
        set("age", 50);      
	set("title",BLU	"���ʷ�����"NOR);
	set("str", 25);
        set("int", 26);
        set("con", 26);
        set("dex", 26);
        set("combat_exp", 50000);
        set("shen_type", 1);
        set("attitude", "peaceful");
	set("max_qi",1000);
        set("max_jing",1000);
set("no_get","��û�취���������");
        set("neili",1000);
        set("max_neili",1000);
	set("jiali",30);
	set("score", 8000);

        set_skill("cuff", 70);
	set_skill("parry",70);
	set_skill("yanling-shenfa",70);
        set_skill("dodge", 70);
	set_skill("force",70);
	set_skill("shenyuan-gong",70);
        set_skill("blade",70);
	map_skill("force","shenyuan-gong");
	map_skill("dodge","yanling-shenfa");
        
        set_temp("apply/attack", 20);
        set_temp("apply/defense", 20);

        setup();
        carry_object(__DIR__"obj/blade")->wield();
        set("inquiry", ([
            "name" : "������٢��ɽׯ�Ļ������¡�\n",
            "here" : "�����ǻ��ʷ���ר�Űѷ����ô������������ʡ�\n",
            "rumors" : "���һ���նε�С�Ӵ����������ˡ�\n",
                         "����" : (: give_tools :),
                         "tools" : (: give_tools :),
 ]));           
}
void init()
{
        object me, ob;
        mapping fam;

        ::init();

        ob = this_player();
        me = this_object();

        if (interactive(ob) 
        && !environment(ob)->query("no_fight")
        && ( (fam = ob->query("family")) && fam["family_name"] != "����Ľ��" ) )
        {
                        command("say �������ʲ�̫�����������������������ʰɣ�����\n");
                        me->set_leader(ob);
                        remove_call_out("kill_ob");
                        call_out("kill_ob", 1, ob); 
        }
}
int give_tools()
{
       object tools,ob,me;
       me = this_object();
       ob = this_player();
       if( !ob->query_temp("mr_job")){
          say (CYN"������˵������û��������˵��������Ҫʲô���ߡ�\n"NOR);
          return 1;
          } 
       if(ob->query_temp("mark/����")){
          say (CYN"������˵�������Ȱѹ��߻��ˣ����칤�߰ɡ�\n"NOR);
          return 1;
          } 
       if(ob->query_temp("mark/����")){
          say (CYN"������˵�����㻹û����(task ok)���»�ɣ�����Ҫʲô���ߡ�\n"NOR);             
          return 1;
          }  
          say(CYN"������˵������Ȼ���Ѿ����˻�Ҿ͸�����ѹ��ߣ�С�ı��ܣ���Ū���ˡ�\n"NOR);
          message_vision("$N����$nһ�ѹ��ߡ�\n", me, ob);
       if(ob->query_temp("mr_job")=="����"){
         tools = new(__DIR__"obj/shuihu");
         tools->move(this_player());
         say(CYN"������˵�����������кܶ໨����ȥ�������н�������(jiaoshui hua)��\n"NOR);
          say(CYN"������˵�����������������⻹���ߣ���ȥ����������(task ok)��\n"NOR);
        ob->set_temp("mark/����",1);
        return 1;
}
}

int accept_object(object me, object obj)
{
      object ob;
      me=this_object();
      ob=this_player();
     if(!(ob->query_temp("mark/����")))
        {
        say(CYN"������˵���㻹û��ɹ�������ô�ͻ����������ˣ�͵����\n"NOR);
                 return 1;
              } 
     if (obj->query("id")!="shui hu")            
        {  
        command("say �㻹�����˰ɣ��Ҵ�û�з����������ߡ�\n");
                 return 1;
              }
               command("nod");
               command("say �ɵò��������˻���˵�!");
               ob->set_temp("mark/����",1); 
               call_out("destroying", 1, me, obj);           
               return 1;
}

void destroying(object me, object obj)
{
        destruct(obj);
        return;
}
