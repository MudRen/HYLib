//snowman 28/02/98
#include <ansi.h>
inherit NPC;
string ask_huijia();
string ask_daojia();
int ask_rob();
void create()
{
        set_name(HIG"СŮ��"NOR, ({ "nuhai"}));
       set("long",
                "һ�����ķǳ���С��СŮ�������ൽ��ʮ������.\n"
                "��������ȴ¶���������ɫ��\n");
        set("attitude", "friendly");
        set("gender", "Ů��");
        set("age", 12);
	set("no_get", 1);
        set("per", 35);
        set("str", 40);
        set("int", 47);
        set("con", 46);
        set("dex", 88);
        set("qi", 9500);
        set("max_qi", 9500);
        set("jing", 9600);
        set("max_jing", 9600);
        set("neili", 18000);
        set("max_neili", 18000);
set_skill("dodge",400);
	set_skill("force", 300);
	set_skill("unarmed", 300);
	set_skill("dodge", 300);
	set_skill("parry", 300);
	set_skill("hand",300);
	set_skill("strike", 300);
        set_skill("sword",300);
	set_skill("bahuang-gong", 300);

	map_skill("force", "bahuang-gong");	        
        set("inquiry", ([
        "�ع�" : (:ask_huijia:) ,
        "����" : (:ask_daojia:) ,
         ]) );
        set("env/wimpy", 40);
        set_temp("apply/attack", 300);
        set_temp("apply/defense",300);
        set_temp("apply/armor", 800);
        set_temp("apply/damage", 100);
        setup();
        carry_object("/d/lingjiu/obj/qingyi")->wear();
        carry_object("/d/lingjiu/obj/doupeng")->wear();
}

void init()
{
        object ob = this_object();
	add_action("do_guard", "guard");
if(this_player()->query("lingjiujob") )
	this_player()->start_busy(1);
if (ob->query("lingsong") == 0 )
{
        remove_call_out("leave");
        call_out("leave",240);
}
}

void leave()
{
        object ob = this_object();
        if (ob->query("lingsong") == 0) {
                message_vision(HIG "СŮ������������Ӧ,�Լ��뿪�ˡ�\n" NOR,this_object());
                destruct(this_object());
                }
        else call_out("leave",30);
}

string ask_huijia()
{
object me=this_player();
object ob = this_object();
if(me->query("lingjiujob") == 0 )
return "�ҿ��������ϴ��������Ǽ�ϸ�ɡ�����\n";
me->apply_condition("lingjiu_song",30);
me->set("lingsong",1);
set_leader(me);
ob->set("lingsong",10);
return "��С�����������ع����ع������н���.\n";
}

string ask_daojia()
{
 object ob,me;
int exp,pot,base_exp;
ob = this_object();
me = this_player();
if(me->query("lingjiujob") == 0 )
return "�ҿ��������ϴ��������Ǽ�ϸ�ɡ�����\n";
if(me->query("lingsong") == 0 )
return "�ҿ��������ϴ��������Ǽ�ϸ�ɡ�����\n";

 if( environment(ob)->query("short")=="���հ��ɽ�")
         {

          set_leader(0);
          write("���ڵ������ˣ��㻤���й�.\n");
pot=880+random(800);
exp=980+random(1300);
             me->add("potential",pot);
             me->add("combat_exp",exp);
             me->set("lingjiujob",0);
me->set("lingsong",0);
             me->apply_condition("lingjiu_song",0);
          write("��ľ����Ǳ�������!!\n");
        call_out("leavet",1);
	   tell_object(me,HIW"�㱻�����ˣ�\n" + 
                       chinese_number(exp) + "��ʵս����\n" +
                       chinese_number(pot) + "��Ǳ��\n"+
                       NOR);
           return "�һع�ȥ��.....\n";  
      }
        else {
                return "��û����!���벻������?\n";
        }
}

int do_guard(string arg)
{
        write(this_player()->query("name")+"�������ڲ�����guard��\n");
        return 1;
}

void leavet()
{
        object ob = this_object();
        destruct(this_object());
}

void unconcious()
{            
	::die();       
}	