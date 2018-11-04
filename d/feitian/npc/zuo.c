#include <ansi.h>
inherit NPC;
inherit F_MASTER;
int ask_kungfu();
int ask_kungfu1();
int ask_kungfu2();
int kungfu_asked1();


void create()
{
	set_name("������֮��", ({ "zuo zhizu", "xiangle" }));
	set("nickname",HIW"ն��"NOR);
	set("gender", "����");
            set("long", 
		" ������˳�ն�����֮���ˣ������·�����ӡ��һ�����Ķ��֡�\n");
	set("age", 23);
            set("dex", 43);
                 set("str", 45);
     set("per", 43);
	set("combat_exp", 3200000);
        set("max_neili",24000);
        set("neili",24000);
        set("max_qi",14000);
        set("eff_qi",14000);
        set("qi",14000);
        set("max_jingli",14000);
        set("eff_jingli",14000);
        set("jingli",4000);
        set_skill("cuff",300);
        set_skill("shayi",200 );
        set_skill("force", 280);
        set_skill("dodge", 200);
                 set_skill("xuanhualiu-quanfa",350);
                 set_skill("unarmed",350);
        set_skill("shayi-xinfa",280);

        map_skill("force","shayi-xinfa");
	map_skill("unarmed","xuanhualiu-quanfa");
	setup();
	carry_object("/clone/misc/cloth")->wear();
            set("inquiry",([
                    "������ȭ��" : (: ask_kungfu :),
                    "ѧ��" : (: ask_kungfu1 :),
                    "����" : (: ask_kungfu2 :),
                    "����" : (: ask_kungfu2 :),
                    "����" : (: ask_kungfu :),
            ]));
          set("chat_chance_combat",80);
          set("chat_msg_combat",({
              (: perform_action,"unarmed.sanchong" :),
              (: exert_function,"recover" :),
          }));
       set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 200);
        set_temp("apply/attack", 200);
          carry_object("/clone/misc/cloth")->wear();
}


void init()
{       
        object ob;

        if( interactive(ob=this_player()) && ob->query_temp("killwei") ) {
                remove_call_out("kill_ob");
                call_out("kill_ob", 1, ob);
        }
}

int ask_kungfu()
{
           object me;
           mapping myparty;
           mapping myfam;
           int skills;

           me=this_player();
           myfam=(mapping)me->query("family");
           myparty=(mapping)me->query("party");
           skills=me->query_skill("xuanhualiu-quanfa",1);

           if ( (!myfam || myfam["family_name"]!="����������") && (!myparty || myparty["party_name"]!=HIG"����������"NOR) )
           {
                   command("say ��������Ե����������ѧ�ģ�");
                   return 1;
           }

           if ( me->query_temp("kungfu_asked1") )
           {
                command("hmm");
                command("say ���׾�ѧ��ֻ��һ�飬ѧ�����Ϳ����Լ����컯�ˡ�");
                return 1;
           }

            if (myfam && myfam["family_name"]=="����������")
{
           if ( me->query("combat_exp")<800000)
           {
                command("say ���ʵս����̫�ͣ�ѧ�����ҵľ�ѧ��");
                return 1;
           }
             if ( me->query_skill("unarmed",1)<180)
           {
                command("say ���ȭ����Ƿ���ѧ�����ҵľ�ѧ��");
                return 1;
           }
               if ( me->query_skill("aikido",1)<180)
           {
                command("say ����ձ��ĺ�����ѧ�����������Ұ�!");
                return 1;
           }

           if ( me->query("max_neili")<1500)
           {
                command("say �����������̫�ѧ�����ҵľ�ѧ��");
                return 1;
           }

             if (skills>=this_object()->query_skill("xuanhualiu-quanfa",1))
             {
                       command("say ���Ѿ�ûʲô�ɽ̵�����");
                       return 1;
             }
             if ((skills*skills*skills/7)>me->query("combat_exp"))
             {
                       command("say ��ľ��鲻����˵����Ҳ��������");
                       return 1;
             }
            if (me->query("jing")<200)
             {
                       command("say ��̫���ˣ���Ϣ��ɡ�");
                       return 1;
             }
                 
            me->improve_skill("xuanhualiu-quanfa",random(10*me->query("int")));
            tell_object(me,"������֮�������һЩ����������ȭ�������ʡ�\n");
          me->receive_damage("jing",me->query("jing")/20);
            
            return 1;

           }
           
            if (myparty && myparty["party_name"]==HIG"����������"NOR)
           {
                  if ( myparty["level"]<4 )
                  {
                       command("say ���׾�ѧ�Ҳ��ܽ��㣬�Բ���");
                       return 1;
                  }
             if ( me->query_skill("unarmed",1)<180)
                  {
                command("say ���ȭ����Ƿ���ѧ�����ҵľ�ѧ��");
                       return 1;
                  }
                  if ( me->query("max_neili")<1500 )
                  {
                       command("say ���������Ƿ���ѧ�����ҵľ�ѧ��");
                       return 1;
                  }
          command("say �ðɣ��㿴��ϸ�ˣ���ֻ����һ�顣");
           message_vision(HIY"$N����һ���ʯ��΢��ȭ������ʯͷ��һ������ʯͷ�����һ�ѷ�ĩ��\n"NOR,this_object());
           if ( me->query("int")<30 )
           {
                  message_vision(YEL"$N���˰��죬�������ã�����������̫���ˣ����ղ��˾��衣\n"NOR,me);
                      me->set_temp("kungfu_asked1",1);
                     return 1;
           }
                 message_vision(HIC"$N���˰���,���������׾�ѧ�ľ��衣\n"NOR,me);
                      me->set_temp("kungfu_asked1",1);
                     me->set_skill("xuanhualiu-quanfa",1);
                     return 1;
           }

           return 0;
}

int ask_kungfu1()
{
           object me;
           mapping myparty;
           mapping myfam;

           me=this_player();
           myfam=(mapping)me->query("family");
           myparty=(mapping)me->query("party");

           if ( (!myfam || myfam["family_name"]!="����������") && (!myparty || myparty["party_name"]!=HIG"����������"NOR) )
           {
                   command("say ���뱾�ź��޹ϸ𣬴˻��Ӻ�̸��");
                   return 1;
           }
           
           command("smile");
           command("say �ұȽϾ�ͨȭ����������������ȭ�������ʡ�");
           
           return 1;
           
}
int ask_kungfu2()
{
           object me;
           mapping myparty;
           mapping myfam;
           int skills;

           me=this_player();
           myfam=(mapping)me->query("family");
           myparty=(mapping)me->query("party");
            skills=(int)me->query_skill("unarmed",1);

           if ( (!myfam || myfam["family_name"]!="����������") && (!myparty || myparty["party_name"]!=HIG"����������"NOR) )
           {
                   command("say ���뽣�ĺ��޹ϸ𣬴˻��Ӻ�̸��");
                   return 1;
           }
           
             if (skills>=this_object()->query_skill("xuanhualiu-quanfa",1))
             {
                       command("say ���Ѿ�ûʲô�ɽ̵�����");
                       return 1;
             }

           if ((skills*skills*skills/7)>me->query("combat_exp"))
            {
                      command("say ��ľ��鲻����˵����Ҳ��������");
                      return 1;
            }

           if (me->query("jing")<200)
            {
                      command("say ��̫���ˣ���Ϣ��ɡ�");
                      return 1;
            }
                
           me->improve_skill("unarmed",random(5*me->query("int")));
           tell_object(me,CYN"������֮�������һЩ����ȭ�������ʡ�\n"NOR);
          me->receive_damage("jing",me->query("jing")/20);
           
           return 1;
           
}

