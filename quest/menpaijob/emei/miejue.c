// miejue.c ���ʦ̫
// Modified by That Oct.1997
#include <command.h>
#include <ansi.h>

inherit NPC;
inherit F_MASTER;
string ask_job();
string ask_for_quit();
mixed out_master(mixed arg);
int ask_zhou();
int ask_guo();
int ask_dragon();
int ask_jiuyin();

mapping *quest = ({
      (["place":                "������",
       "start" :              "/d/dali/northgate",]),  
      (["place":                "��������",
       "start" :              "/d/city/jiaowai5",]),  
     (["place":                "���Ҳ���",
       "start" :              "/d/emei/caopeng",]),
     (["place":                "��������",
       "start" :              "/d/city/ximen",]),
     (["place":                "ѩɽ��·",
       "start" :              "/d/xueshan/tulu2",]),
     (["place":                "������԰",
       "start" :              "/d/suzhou/liuyuan",]),
     (["place":                "���ݺ�ɽ��",
       "start" :              "/d/suzhou/hanshansi",]),
     (["place":                "���ݷ�����",
       "start" :              "/d/hangzhou/feilaifeng",]),
     (["place":                "���ݾ�����",
       "start" :              "/d/hangzhou/jingcisi",]),
     (["place":                "���ݴ�΢ͤ",
       "start" :              "/d/hangzhou/cuiweiting",]),
     (["place":                "���ݾ۾�԰",
       "start" :              "/d/hangzhou/jujingyuan",]),
     (["place":                "�置��Ϫ��",
       "start" :              "/d/dali/yixibu",]),  
      (["place":                "��������㳡",
       "start" :              "/d/city/guangchang",]),  
      (["place":                "�����غ����",
       "start" :              "/d/hangzhou/dadao1",]), 
      (["place":                "���ݶ���",
       "start" :              "/d/hangzhou/duanqiao",]), 
      (["place":                "����������",
       "start" :              "/d/hangzhou/lingyinsi",]), 
      (["place":                "���޺�����",
       "start" :              "/d/xingxiu/beijiang",]), 
      (["place":                "�䵱������",
       "start" :              "/d/wudang/santiangate",]), 
      (["place":                "����ʮ����",
       "start" :              "/d/emei/shierpan3",]), 
      (["place":                "����ǧ����",
       "start" :              "/d/emei/qianfoan",]), 
      (["place":                "���Ҿ�ʮ�ŵ���",
       "start" :              "/d/emei/jsjdg1",]), 
      (["place":                "���̺�������",
       "start" :              "/d/mingjiao/htqmen",]), 
      (["place":                "�����һ������",
       "start" :              "/d/mingjiao/lhqhoumen",]), 
      (["place":                "���ݶ���",
       "start" :              "/d/fuzhou/dongmen",]), 
      (["place":                "���ݱ����",
       "start" :              "/d/fuzhou/beidajie",]), 
      (["place":                "���޺�ɳĮ",
       "start" :              "/d/xingxiu/shamo2",]),
      (["place":                "������ʯ��",
       "start" :              "/d/shaolin/shijie4",]),
      (["place":                "����ʯ��",
       "start" :              "/d/xiangyang/walle1",]),
      (["place":                "��ɽ�����",
       "start" :              "/d/huashan/husun",]),
      (["place":                "��ɽ��Ů��",
       "start" :              "/d/huashan/yunu",]),
      (["place":                "Ľ��С��",
       "start" :              "/d/mr/xiaojing1-2",]),
      (["place":                "Ľ��������",
       "start" :              "/d/mr/liulin",]),
      (["place":                "�����ͽ�",
       "start" :              "/d/dali/dahejiewest",]),
      (["place":                "���ݳǱ���",
       "start" :              "/d/suzhou/beimen",]),
      (["place":                "���ݳ������",
       "start" :              "/d/suzhou/xuanmiao",]),
      (["place":                "������ɽ�ŵ�",
       "start" :              "/d/shaolin/smdian",]),
      (["place":                "����������",
       "start" :              "/d/shaolin/zoulang7",]),
      (["place":                "�䵱ɽ·",
       "start" :              "/d/wudang/shanlu3",]),
      (["place":                "�����°����þŲ�",
       "start" :              "/d/shaolin/banruo9",]),
      (["place":                "ѩɽɽ��",
       "start" :              "/d/xueshan/shanjiao",]),
      (["place":                "���Ҿ��϶�",
       "start" :              "/d/emei/jiulaodong",]),
       (["place":                "���ҹŵ���",
       "start" :              "/d/emei/gudelin1",]),
       (["place":                "���Ź�",
       "start" :              "/d/city4/hanguguan",]),
       (["place":                "����ɽ��",
       "start" :              "/d/city4/zhongnan",]),
       (["place":                "����",
       "start" :              "/d/fuzhou/fzroad8",]),
       (["place":                "��ˮ�ϰ�",
       "start" :              "/d/shaolin/hanshui1",]),
       (["place":                "����ɽ����",
       "start" :              "/d/huashan/jzroad5",]),
       (["place":                "��ɽ����",
       "start" :              "/d/xingxiu/shanjiao",]),
       (["place":                "��ɽ����",
       "start" :              "/d/huashan/path1",]),
       (["place":                "ƽ����",
       "start" :              "/d/heimuya/pingdingzhou",]),
       (["place":                "��ʯ��",
       "start" :              "/d/heimuya/road1",]),      
       (["place":                "��ɽ���ϴ��",
       "start":                "/d/village/sexit",]),
       (["place":                "���ӹŵ�",
       "start":                "/d/fuzhou/fzroad7",]),
       (["place":                "��ʶ�",
       "start":               "/d/taishan/yuhuang",]),
       (["place":                "����ɽ",
       "start":                "/d/xingxiu/xxroad3",]),
       (["place":                "��ɽɽ·",
       "start":                "/d/xingxiu/tianroad1",]),
       (["place":                "������",
       "start":                "/d/xingxiu/jiayuguan",]),
       (["place":                "���������",
       "start":                "/d/beijing/xidan1",]),
       (["place":                "����㳡",
       "start":                "/d/baling/guangchang",]),
       (["place":                "���������",
       "start":                "/d/beijing/wangfu2",]),
       (["place":                "ȫ��̱�",
       "start":                "/d/quanzhen/jiaobei",]),
       (["place":                "������",
       "start":                "/d/gumu/juyan",]),
       (["place":                "����ͷ",
       "start":                "/d/guanwai/laolongtou",]),
       (["place":                "���˳�",
       "start":                "/d/quanzhou/jiaxing",]),
       (["place":                "��������",
       "start":                "/d/city/ximen",]),
       (["place":                "��ϼ��",
       "start":                "/d/fuzhou/fzroad1",]),
       (["place":                "��Զ",
       "start":                "/d/taishan/yitian",]),
       (["place":                "С����",
       "start":                "/d/guanwai/tuwu",]),
       (["place":                "�¹س�",
       "start":                "/d/dali/xiaguan",]),
       (["place":                "������ʯ��",
        "start":                "/d/dali/shilin1",]),
        (["place":                "���ˮ�ٲ�",
        "start":                "/d/dali/dadieshui",]),
        (["place":                "��٤��",
        "start":                "/d/dali/luojiadian",]),
        (["place":                "������",
        "start":                "/d/dali/yangzong",]),
        (["place":                "̫����",
        "start":                "/d/songshan/taishique",]),
        (["place":                "����ʯ��",
        "start":                "/d/shaolin/shijie7",]),
        (["place":                "����Ͽ",
        "start":                "/d/songshan/tieliang",]),
        (["place":                "������Ժɽ��",
        "start":                "/d/songshan/junjigate",]),
        (["place":                "���ԭ",
        "start":                "/d/gumu/shenheyuan",]),
        (["place":                "����ɽ��У��",
        "start":                "/d/gumu/daxiaochang",]),
        (["place":                "������",
        "start":                "/d/huashan/jinsuo",]),
        (["place":                "ƽ��ʯ",
        "start":                "/d/huashan/pingxinshi",]),
        (["place":                "ǧ�ߴ�",
        "start":                "/d/huashan/qianchi",]),
        (["place":                "ɽ���ٲ�",
        "start":                "/d/huashan/shanhongpb",]),
        (["place":                "������",
        "start":                "/d/emei/qingyinge",]),
        (["place":                "ʮ����",
        "start":                "/d/emei/shierpan1",]),
        (["place":                "���϶���",
        "start":                "/d/emei/jldongkou",]),
        (["place":                "��ʮ�ŵ���",
        "start":                "/d/emei/jsjdg2",]),
        (["place":                "ǧ����",
        "start":                "/d/emei/qianfoan",]),
        (["place":                "����ɽ�յ�",
        "start":                "/d/gumu/kongdi",]),
        (["place":                "����ɽ����",
        "start":                "/d/gumu/zhufeng",]),
        (["place":                "������",
        "start":                "/d/mingjiao/shanlu3",]),
         (["place":                "�һ������",
        "start":                "/d/mingjiao/lhqmen",]),
        (["place":                "ѩɽ��ɽ��",
        "start":                "/d/xueshan/shanmen",]),
        (["place":                "��ˮ�����",
        "start":                "/d/mingjiao/hsqmen",]),
        (["place":                "��ˮ�����",
        "start":                "/d/mingjiao/hsqmen",]),
        (["place":                "�����",
        "start":                "/d/mingjiao/hsqmen",]),
        (["place":                "��ʯ���",
        "start":                "/d/wudang/wdroad1",]),
        (["place":                "�����",
        "start":                "/d/city4/road1",]),
        (["place":                "�����",
        "start":                "/d/taishan/yidao",]),
        (["place":                "�ٵ�",
        "start":                "/d/quanzhen/guandao2",]),
        (["place":                "����",
        "start":                "/d/quanzhen/dongjie",]),
        (["place":                "���Ҵ���",
        "start":                "/d/quanzhen/fu-damen",]),
        (["place":                "ɽ·",
        "start":                "/d/quanzhen/shanlu1",]),
        (["place":                "С��ׯ",
        "start":                "/d/quanzhen/xiaocun",]),
        (["place":                "���޺�",
        "start":                "/d/xingxiu/xxh2",]),
        (["place":                "��ɽ����",
        "start":                "/d/xingxiu/shanjiao",]),
        (["place":                "˿��֮·",
        "start":                "/d/xingxiu/silk2",]),
        (["place":                "����������",
        "start":                "/d/city4/westgate",]),
        (["place":                "�����Ƕ���",
        "start":                "/d/city4/eastgate",]),
        (["place":                "�Ƕ���",
        "start":                "/d/city4/eastgate",]),
        (["place":                "������",
        "start":                "/d/huashan/shangtianti",]),
        (["place":                "����",
        "start":                "/d/xiaoyao/shulin3",]),
        (["place":                "�ϴ��",
        "start":                "/d/xiaoyao/shulin3",]),});    

string ask_for_quit();
mixed out_master(mixed arg);

void create()
{
        set_name("���ʦ̫", ({ "miejue shitai","miejue","shitai"}));
        set("long",
                "���Ƕ����ɵĵ��������ӣ����ζ����������ˡ�\n");
        set("gender", "Ů��");
        set("age", 62);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("shen", 100000);
        set("class", "bonze");
set_temp("huifeng/jue",1);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.mie" :),
                (: perform_action, "sword.sanqing" :),
                	(: perform_action, "sword.jue" :),
                	(: perform_action, "sword.liaoyuan" :),                		
                (: perform_action, "sword.sanqing" :),
                (: perform_action, "strike.puzhao" :),
                (: perform_action, "strike.puzhao" :),
                (: perform_action, "strike.bashi" :),
                (: perform_action, "finger.lingkong" :),
                (: perform_action, "finger.lingkong" :),
                (: exert_function, "daxiao" :),
                (: exert_function, "fengyun" :),
                (: exert_function, "longhe" :),
                (: exert_function, "tiandi" :),                                
                (: exert_function, "juemie" :), 
        }) );
        set("inquiry",([
                "���"  : "ƶ��ֻ֪����ɱħ������ȵ��ӡ�",
                "����"  : "ƶ��ֻ֪����ɱħ������ȵ��ӡ�",
                "����"  :  (: ask_for_quit :),
		"������" : (: ask_zhou :),
		"����" : (: ask_guo :),
		"����" : (: ask_guo :),
		"��������" : (: ask_dragon :),
		"��������" : (: ask_dragon :),
		"�����ٳ�ƪ" : (: ask_jiuyin :),
                "����" : (: ask_job :),
                "ɱħ" : (: ask_job :),
                "job" : (: ask_job :),
        ]));

        set("str", 50);
        set("int", 55);
        set("con", 55);
        set("dex", 55);
        set("per", 20);

        set("max_qi", 28000);
        set("max_jing", 28000);
        set("neili", 38000);
        set("max_neili", 38000);
        set("jingli", 11500);
        set("max_jingli", 11500);

        set("combat_exp", 8500000);
        set("score", 1000);
        set_skill("persuading", 500);
        set_skill("throwing", 250);
        set_skill("force", 300);
        set_skill("dodge", 250);
        set_skill("finger", 250);
        set_skill("parry", 250);
        set_skill("strike", 250);
        set_skill("sword", 280);
        set_skill("blade", 280);
        set_skill("literate", 260);
        set_skill("mahayana", 500);
        set_skill("buddhism", 500);
        set_skill("jinding-zhang", 380);
        set_skill("tiangang-zhi", 380);
        set_skill("huifeng-jian", 380);
        set_skill("yanxing-dao", 380);
        set_skill("zhutian-bu", 380);
        set_skill("linji-zhuang", 380);
        set_skill("bagua-dao", 380);
        set_skill("bagua-zhang", 380);

        set_skill("huixin-strike", 380);
        set_skill("piaoxue-hand", 380);
        set_skill("yinlong-whip", 380);
        set_skill("yitian-jian", 380);
        set_skill("whip", 220);
        set_skill("hand", 220);
        map_skill("force","linji-zhuang");
        map_skill("finger","tiangang-zhi");
        map_skill("dodge","zhutian-bu");
        map_skill("strike","jinding-zhang");
        map_skill("sword","huifeng-jian");
        map_skill("blade","yanxing-dao");
        map_skill("parry","huifeng-jian");


if (random(2)==0)
{
set("isyt",1);
	        map_skill("hand","piaoxue-hand");
        map_skill("strike","huixin-strike");
        map_skill("parry","yitian-jian");
        map_skill("sword","yitian-jian");
        prepare_skill("strike", "huixin-strike");
        prepare_skill("hand", "piaoxue-hand");
        set("chat_chance_combat", 99);
        set("chat_msg_combat", ({
                (: perform_action, "sword.fumo" :),
                (: perform_action, "sword.yitian" :),
                (: perform_action, "strike.cuixin" :),
                (: perform_action, "strike.gu" :),
                (: perform_action, "hand.yun" :),
                (: perform_action, "hand.zhao" :),
                (: perform_action, "finger.lingkong" :),
                (: exert_function, "daxiao" :),
                (: exert_function, "fengyun" :),
                (: exert_function, "longhe" :),
                (: exert_function, "tiandi" :),                                
                (: exert_function, "juemie" :), 
        }) );
}
else
{
        prepare_skill("strike", "jinding-zhang");
        prepare_skill("finger", "tiangang-zhi");	
}
//        map_skill("magic","bashi-shentong");
        create_family("������", 3, "������");
	set_temp("apply/attack",190);
	set_temp("apply/defense",190);
	set_temp("apply/armor",900);
	set_temp("apply/damage",900);
        setup();

if (random(3)==0 && query("isyt")==1) carry_object("/clone/box/baowu/57")->wield();
else         carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/city/obj/cloth.c")->wear();
}


void attempt_apprentice(object ob)
{
   mapping ob_fam;
   mapping my_fam  = ob->query("family");

   string name, new_name;
   name = ob->query("name");

   if (!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "������")
   {
      command("say " + RANK_D->query_respect(ob) + "�뱾��������������֪�˻��Ӻ�̸��");
      return;
   }
   switch (random(2))
   {
        case 1: break;
        default:
           if ((string)ob->query("class")!="bonze" )
           {
               command ("say �����ӷ�ƶ�᲻���׼ҵ��ӡ�");
               return;
           }
           else
           {
               command ("say �����ӷ�ƶ�᲻�յ��ӡ�");
               return;
           }
   }
   if ((int)ob->query_skill("mahayana",1)<90||(int)ob->query_skill("linji-zhuang",1)<90)
   {
      command("say �㱾�ŵĹ�����Ϊ��̫�͡�");
      return;
   }
   if ((int)ob->query("shen") < 50000)
   {
      command("say " + RANK_D->query_respect(ob) + "����������֮�»����Ĳ�����");
      return;
   }
   if ((string)ob->query("class")=="bonze" )
   {
        name = ob->query("name");
        new_name = "��" + name[2..3];
        ob->set("name", new_name);
        command("say �ӽ��Ժ���ķ�������" + new_name + "����ϲ���Ϊ���ҵ��Ĵ�����!");
   }

   command("say �����ӷ����գ����գ��ðɣ��Ҿ��������ˡ�");
   command("say ϣ�������Դȱ�֮�ģ����ǻ�֮����Ŭ�����ƣ��ö�������");
   command("recruit " + ob->query("id"));
}

string ask_for_quit()
{
    object me;
    mapping myfam;
    me = this_player();

    myfam = (mapping)me->query("family");
    if (!myfam || (myfam["family_name"] != "������")) 
        return ("��Ͷ���û��ԨԴ��ƶ�᲻�Ҹ��㻹�ס�\n");
    if( (string)me->query("class")!="bonze" )
        return "�����ӷ𣡳����˲���ڿ����Ѿ����׼����ˡ�\n";
    me->set_temp("pending/quit_bonze", 1);
        command ("say �����ӷ����գ����գ���һ��Ҫ���ף���Ҳ��������\n");
        command ("say �ҽ���ȥ�㲿���书�������(kneel)������\n");
        return "�����Ը���׵ģ��Ͱ����ڴ������ɡ�\n";
}

int do_kneel()
{
    object me,ob;
    mapping myfam;
    ob = this_object();
    me = this_player();
    myfam = (mapping)me->query("family");
    if (!myfam || (myfam["family_name"] != "������")) 
{
        command ("say ��Ͷ���û��ԨԴ��ƶ�᲻�Ҹ��㻹�ס�\n");
return 1;
}
    if( (string)me->query("class")!="bonze" )
{
        command ("say �����ӷ𣡳����˲���ڿ����Ѿ����׼����ˡ�\n");
return 1;
}
    if (!me->query_temp("pending/quit_bonze"))
{
        command ("say �����ӷ�������ʲô����\n");
return 1;
}
command ("say �ã����������ҽ���ȥ���㱾�ŵ��书��\n");
if (me->query_skill("linji-zhuang")>1)
{
me->delete_skill("linji-zhuang");
me->map_skill("force");
me->prepare_skill("force");
me->reset_action();
me->set("class","emei");
me->delete_temp("pending/quit_bonze");
}
message_vision(RED"\n$N��$n�����ϵ��˼���,$n�����������һ����ȫû�ˣ���\n"NOR, ob, me);
command ("say �����ڿ�ʼ����Ͳ��ǳ������ˣ���\n");
return 1;
}

int accept_object(object me, object obj)
{
   object ob=this_object();
   if(!me || environment(me) != environment()) return 0;
   if(!objectp(obj)) return 0;
   if(!present(obj, me)) return notify_fail("��û�����������");        
   if(userp(obj)){
       command("consider "+(string)me->query("id"));
       command("say ���ø�����������ƭƶ�᣿");
       return 0;
       }
   if(me->query_temp("emjob2") <2){
       command("consider "+(string)me->query("id"));
       command("say ��������ô���ģ�ɱ�˼������ˣ�");
       return 0;
       }       
   if(obj->query("id") == "mingjiao ling" && obj->query("owner") == me->query("id")){
       command("nod "+(string)me->query("id"));
       command("say �ɵúã�\n");
       message_vision(HIY"$N��$n"HIY"��������\n"NOR,ob, obj);
       remove_call_out("destroying");
       call_out("destroying", 0, obj, ob, me);                       
       return 1;
       }
   if(obj->query("money_id")) {
       command("pat " + me->query("id"));
       command("say ƶ����ҪǮ��ʲô?");
       return 0;
       }
//   if(obj->query("owner") != me->query("id")){
//       command("hehe "+(string)me->query("id"));
//       command("say �����������ɲ�����ɵġ�");
//       /return 1;
//       }
//   else return 0;       
}
void destroying(object obj, object ob, object me)
{   
   object n_money;
   int exp,pot;
   if(obj) destruct(obj);
   if(!ob) return;
   if(!me || environment(me) != environment()){
      command("say �ף����أ�");
      return;
      }
   command("pat "+me->query("id"));
   message_vision(HIY"$N��$n˵������������ü�Ϊ��ɫ��ƶ���ָ�������ֹ����.\n"NOR,ob, me);
   me->set_temp("robjob_exp", 380+(me->query_temp("biaoshi")*(random(30)+60)));
   me->add("combat_exp", me->query_temp("robjob_exp"));
   me->add("potential", 360+me->query_temp("biaoshi")*60);
  me->add("shen",100);
  me->add("score",10);
   tell_object(me, "�㱻������"+chinese_number(me->query_temp("robjob_exp"))+"�㾭��ֵ��\n"+chinese_number(200+me->query_temp("biaoshi")*60)+"��Ǳ��\n");
   tell_object(me, "�������������ǿ�ˣ����˽���������ǿ�ˡ�\n");
destruct(present("mingjiao ling",ob));

me->delete_temp("emjob2");
   me->delete_temp("xx_rob");
   ob->delete_temp("job_asked");
   me->delete_temp("robjob_exp");
   me->delete_temp("biaoshi");
   return;      
}
string ask_job()
{
  object me, ob,obn;
  mapping aquest;
  int exp, j;
  aquest = quest[random(sizeof(quest))];
  me = this_player();
  ob = this_object();
  exp = me->query("combat_exp"); 
 
    if(ob->query_temp("job_asked") == me->query("id")) 
            return "���ǽ�����ȥ�����������ô�������";
    if( me->query("family/family_name") != "������")
            return "�����������ļ�ϸ��";
      if( (int)me->query_skill("linji-zhuang",1) < 50)
            return "ƶ����Ϊ��ı����ڹ�̫���ˡ�";

    if(me->query_condition("emeijob"))
            return "ƶ�����ڻ�û�еõ��κ���Ϣ����Ȼ�������ɡ�";


    if(exp>=600000) j=5;
    else if(exp>=500000) j=4;
    else if(exp>=400000) j=3;
    else if(exp>=300000) j=2;   
    else j=3;   
  
    me->set_temp("rob_job", 1);
    me->delete_temp("biaoshi");
    message_vision(CYN"\n$N˵��,����Ϣ˵ħ����һ����������ı,�����ɲ�����\n"NOR, ob, me);
    ob->set_temp("job_asked", me->query("id"));
    ob->set_temp("dest", "emeijob");
    ob->set_temp("start_place", aquest["start"]);
    ob->set_temp("place", aquest["place"]);
    me->set_temp("j", j);    
    me->apply_condition("emeijob", 15);
    me->start_busy(1);
    obn = new(__DIR__"shangdui");
    obn->move(aquest["start"]);
    obn->set("arg", ob->query_temp("dest"));
    me->set_temp("rob_start", 1);
    return "���ȥ"+ob->query_temp("place")+"����(xiaomie)ħ�̶��顣\n";    
}

void init()
{
   object ob, where, me;
   ::init();
   ob=this_object();
   where = environment(ob);
   if(ob->query_temp("dest")){
     if(interactive(me = this_player()) && me->query_temp("rob_job")
        && ob->query_temp("job_asked") == me->query("id")
        && file_name(where) == ob->query_temp("start_place")) {
           remove_call_out("waiting");
           call_out("do_back",120,me);
	    call_out("waiting", 1, ob, me);
           }
     else{
         remove_call_out("do_back");
         call_out("do_back", 90, ob);
         }
     }
  add_action("do_kneel", "kneel");
}
void waiting(object ob, object me)
{   
    if(!ob || !living(me)) return;
    command("nod "+me->query("id"));
    command("say �ã����Ǿ�����������������ɡ�");
    ob->set_temp("wait_target", 1);
    me->set_temp("wait_target", 1);
    remove_call_out("wait_target");
    call_out("wait_target", 30, ob, me);
    return; 
}
void do_back(object me)
{
        me->delete_temp("wait_target");
        me->delete_temp("start_place");
        me->delete_temp("place");
        me->delete_temp("dest");
        message_vision("$Nת��ɽ�𣬼�������Ͳ����ˡ�\n", me);
        me->move("/d/emei/hcahoudian");  
        message_vision("$N����ææ�����˹�����\n", me);
        remove_call_out("del_temp");
        call_out("del_temp", 400, me);             
}
void del_temp(object me) {me->delete_temp("job_asked");}

int wait_target(object ob, object me)
{
   object obj;
   if(!objectp(present(me, environment(ob)))){
       message_vision("$N˵����Ү������ô�����ˣ�\n", ob);
       remove_call_out("do_back");
       do_back(ob);
       return 1;
       }
   if(!objectp(ob = present("miejue shitai", environment(me)))){ 
       tell_object(me,"�㷢�����ʦ̫�����ˣ�ֻ��ת���뿪��\n");
       tell_room(environment(me), me->name()+"ͻȻһ��ãȻ�ı��飬��������Ҫ�뿪�ˡ�\n", ({ me }));
       me->delete_temp("rob_job");
//       me->clear_condition("rob_task");
       me->delete_temp("wait_target");
       return 1;
       }

    obj = new(__DIR__"shangdui");
    obj->move(environment(me)); 
    obj->set("arg", ob->query_temp("dest"));
    message_vision(HIY"\nֻ��һ��Ų���������һ�����̵������������ǰ��\n\n"NOR, ob);
    tell_object(me,"�������ڳ����ˣ�\n"); 
    message_vision(HIY"$N����$n������������������(xiaomie)ħ�̶��飬�����Ը������ˣ�\n"NOR, ob, me); 
    message_vision("˵��$N�ͳ���ǰȥ���ͼ������̸��ִ�׷���ˡ�\n", ob);   
    remove_call_out("do_back");
    do_back(ob);
    me->delete_temp("wait_target");
    me->set_temp("rob_start", 1);
}
int ask_guo()
{
    object me=this_player();
    if( me->query("shen") < -10000 ) {
        command("say ����һ��а�������Ҵ��������������ţ�\n");
        command("consider "+ me->query("id"));
        return 1;
    }

    command("say ���ɵĴ�����ʦ��Ů�������ǵ������������СŮ���������������������£���ƽ����
����գ���һ���о����̵ı�������������书���������ķ��˻��ػ�Ů�����Ǵ�������
�����ۼ�Ԫ���ƴ������ղ����أ����򸾶��˾�����������������֪�䲻�ɶ�Ϊ֮�ĳ�
�ľ��ң����������ľ�������ʹ�ʧ�����񲻿�ϧ���ο��������ɹ�����Ȼһʱռ������
�����Һ����վ�����Ϊ����ū�����պ���ԭѪս���Ǳ������书������м�����ô���
�����Ƹ�ø��ֽ��ˣ��������������ͱ��ɹ���ʦ��һ�������ؽ����ˣ��ټ���������
��������һ����������һ�����콣��");
	me->set_temp("jiuyin/emei", 1);
        return 1;
}

int ask_zhou()
{
    object me=this_player();
    if( me->query_temp("jiuyin/emei") >= 1 ) {
        command("say �����������ɵĵ��Ĵ����ӣ��˿���Ȼ������λʦ梣��պ�ȴ�ǲ���������");
        me->set_temp("jiuyin/emei", 2 );
        return 1;
    }
    command("say ��������ʲô��\n");
    command("say " + me->query("name") + "��Ȼ�ǿ���������Ҫ�����������С�");
    command("consider " + me->query("id") );
    return 1;
}

int ask_dragon()
{
    object me=this_player();
    object ob = this_object();
    if( me->query_temp("jiuyin/emei") < 4 ) {
        command("say ���ɵ��ش���������ô֪���ˣ���������");
        ob->set("neili", 10000);
        ob->kill_ob(me);
        return 1;
    }
    command("say ��Ȼ�������ѳɴ���������͸�������İɡ�");
    me->set_temp("jiuyin/emei", 5 );
    return 1;
}

int ask_jiuyin()
{
	object me=this_player();
	object ob=this_object();
	if (me->query("jiuyin/emei")) {
if(environment(ob)->query("short")!="�����ֺ��")
{
tell_object(me,"����ʲô�ط�������ط����ܸ���\n");
 return 1;
}
if(environment(ob)->query("already"))
{
tell_object(me,"�������ˣ������Ѿ��Ѿ����ٳ�ƪ������!\n");
return 1;
}



		if (present("jiuyin sucheng", me)) {
			command("say �Ҳ����Ѿ�������ô��");
			return 1;
		}
		if( me->query_skill("xianglong-zhang", 1) > 0)
        		command("say ����ʮ�������Ѿ�ѧ�ˣ��������ٳ�ƪ�����ȥѧ�ɡ�");
		else
        		command("say �����ѧ·���뽵��ʮ���Ƶĸ��������������Ȿ�����ٳ�ƪ�����ȥѧ�ɡ�");
        	
                environment(ob)->set("already",1);

		new("/clone/book/jiuyin-sucheng")->move(me);
		message("channel:rumor", MAG"��ҥ�ԡ�ĳ�ˣ�"+me->query("name")+"�õ������ٳ�ƪ����\n"NOR, users());
		return 1;
	}
	return 0;
}
