//wuji.c
inherit NPC;
string ask_huijia()
{
object me=this_player();
set_leader(me);
return "лл��Ը�����һؼ�.\n";
}

string ask_daojia()
{
 object ob,me;
 ob = this_object();
 me = this_player();
 if( environment(me)->query("short")=="�ż�ס��ɽ��")
         {

          set_leader(0);
if (me)
{
          me->set_temp("marks/bing",1);
          write("���ڵ����ˣ�̫лл����.\n");
          me->start_busy(2);
}
       call_out("destroying", 1,  ob);                       
           return "�޼ɸյ����ֳ�ȥ����.....\n";  
      }
        else {
                return "��û��.\n";
        }
}
void greeting(object ob)
{
        tell_object(ob,"�޼�˵:����������,�Ҳ��ҳ�ȥ!\n");
}
void create()
{
        set_name("���޼�",({ "zhang wuji" }) );
        set("gender", "����" );
        set("age", 6);
        set("long", "����лѷ����,�Ŵ�ɽ�������صĶ���\n");
        set("combat_exp", 500);
        set("shen_type", 200);
        set("str", 10);
        set("dex", 10);
        set("con", 10);
        set("int", 10);
        set("attitude", "friendly");
        set("chat_chance", 6);
        set("inquiry", ([
        "�ؼ�" : (:ask_huijia:) ,
        "����" : (:ask_daojia:) ,
         ]) );

        set("neili",200);
        set_skill("dodge", 40);
        set_skill("unarmed", 40);
        set_skill("force",20);        
        set_skill("parry", 40);
        set_skill("qishang-quan", 20);
        set_skill("literate", 10);
map_skill("unarmed", "qishang-quan");
         setup();
        carry_object("/d/binghuodao/npc/obj/skin")->wear();
}

void init()
{
        greeting( this_player());
}

void destroying(object ob)
{   
   destruct(ob);
}