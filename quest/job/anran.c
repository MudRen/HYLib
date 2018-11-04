#include <ansi.h>
inherit NPC;

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
       (["place":                "�����",
       "start":                "/d/city/wudao4",]),
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
//});    
string ask_job();

void create()
{
        set_name("���", ({ "ma chou", "ma"}) );
        set("gender", "����" );
        set("nickname", "����");
        set("age", 31);
        set("long", "ס��ɽ��һ��������ͷ�����������������Դ���ڳ�Ϊ����\n");
        set("str", 29);
        set("dex", 26);
        set("con", 24);
        set("int", 22);
        set("per", 18);
        set("shen", -7500);
        set("max_qi", 12000);
        set("max_jing", 12000);
	 set("neili",12000);
	 set("max_neili",12000);
        set("eff_jingli", 11800);
	 set_skill("blade",300);
	 set_skill("zixia-shengong",300);
	 set_skill("fanliangyi-dao",300);
	 map_skill("blade","fanliangyi-dao");
	 
        set("combat_exp", 1750000);
        set("chat_chance_combat", 55);
        set("chat_msg_combat", ({
                (: perform_action, "blade.sanshen" :),
        }));
        set("inquiry", ([
                "����" : (: ask_job :),
                "����" : (: ask_job :),
                "rob" : (: ask_job :),
        ]));        
        setup();
        carry_object("/clone/weapon/gangdao")->wield();
        carry_object("/clone/cloth/cloth")->wear();
        add_money("silver", 10);
}
int accept_object(object me, object obj)
{
   object ob=this_object();
   if(!me || environment(me) != environment()) return 0;
   if(!objectp(obj)) return 0;
   if(!present(obj, me)) return notify_fail("��û�����������");        
   if(userp(obj)){
       command("consider "+(string)me->query("id"));
       command("say ���ø�����������ƭ�ң�");
       return 0;
       }
   if(obj->query("id") == "prize" && obj->query("owner") == me->query("id")){
       command("nod "+(string)me->query("id"));
       command("say �����ģ��ɵúã�\n");
       message_vision(HIY"$N��$n"HIY"�𿪣��ó���һ��ѽ����Ʊ���\n"NOR,ob, obj);
       remove_call_out("destroying");
       call_out("destroying", 5, obj, ob, me);                       
       return 1;
       }
   if(obj->query("money_id")) {
       command("pat " + me->query("id"));
       command("say Ǯ���е��ǣ����Ժ��������Լ��ɡ�");
       return 0;
       }
   if(obj->query("owner") != me->query("id")){
       command("hehe "+(string)me->query("id"));
       command("say �����������ɲ�����ɵġ�");
       return 1;
       }
   else return 0;       
}
void destroying(object obj, object ob, object me)
{   
   object n_money;
   if(obj) destruct(obj);
   if(!ob) return;
   if(!me || environment(me) != environment()){
      command("say �ף����أ�");
      return;
      }
   command("pat "+me->query("id"));
   message_vision(HIY"$N��$n˵������������ü�Ϊ��ɫ��������õõĲ��֣���ȥ�ɣ�\n"NOR,ob, me);
   n_money = new("/clone/money/gold");
   n_money->move(me); 
   n_money->add_amount(1);
   me->set_temp("robjob_exp", 50+(me->query_temp("biaoshi")*(random(30)+30)));
   me->add("combat_exp", me->query_temp("robjob_exp"));
   me->add("potential", me->query_temp("biaoshi")*20);
   tell_room(environment(me), me->name()+"����Ǯ����Ľ��ӣ����ϵļ��ⲻס�ز������۾�ɢ����һ����ֵĹ�â��\n" NOR, ({ me }));     
   tell_object(me, "�㱻������"+chinese_number(me->query_temp("robjob_exp"))+"�㾭��ֵ��\n"+chinese_number(me->query_temp("biaoshi")*20)+"��Ǳ��\n");
   me->delete_temp("robjob_exp");
   me->delete_temp("biaoshi");
   ob->delete_temp("job_asked");
   ob->delete_temp("robjob_asked");
   ob->delete_temp("dest");
   ob->delete_temp("start_place");
   ob->delete_temp("place");
   return;      
}
string ask_job()
{
  object me, ob;
  mapping aquest;
  int exp, j;
  aquest = quest[random(sizeof(quest))];
  me = this_player();
  ob = this_object();
  exp = me->query("combat_exp"); 
 
   // if(me->query_condition("rob_task"))
   //         return "�����ڻ�û�еõ��κ���Ϣ����Ȼ�������ɡ�";
    if(me->query_condition("job_busy"))
            return "�����ڻ������������Ȼ�������ɡ�";       
    if(ob->query_temp("job_asked") == me->query("id")) 
            return "���ǽ�����ȥ�����������ô���������";
    if(ob->query_temp("job_asked")) 
            return "�ٺ٣��������ˣ�����һ�ΰɡ�";
    if(me->query("shen") > -10000) return "�ߣ���������ĳ��������ڰ����������㲻��Ҳ�ա�";
    if(exp>=600000) j=6;
    else if(exp>=500000) j=5;
    else if(exp>=400000) j=5;
    else if(exp>=300000) j=4;   
    else j=3;   
  
    me->set_temp("rob_job", 1);
    me->delete_temp("biaoshi");
    message_vision(CYN"\n$N����һЦ��˵���������쳤���ھֻ���һ���ھ������㹻���ͺ���һ��ȥ�����ɡ�\n"NOR, ob, me);
    ob->set_temp("job_asked", me->query("id"));
//    ob->set_temp("dest", aquest["name"]);
    ob->set_temp("dest", "robjob");
    ob->set_temp("start_place", aquest["start"]);
    ob->set_temp("place", aquest["place"]);
    me->set_temp("j", j);    
    me->apply_condition("rob_task", 60+(j*20));
    me->start_busy(1);
    remove_call_out("going");
    call_out("going", 30, ob); 
    return "�һ���Щ��Ҫ�죬����ȥ"+ob->query_temp("place")+"���ҡ�\n";    
}
void going(object me)
{
       message_vision("$N����ææ�����˳�ȥ��\n", me);       
       me->move(me->query_temp("start_place"));
	message_vision("$N����ææ�����˹�����\n", me);       
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
	  me->move("/d/tiezhang/lx");  
        message_vision("$N����ææ�����˹�����\n", me);
        remove_call_out("del_temp");
        call_out("del_temp", 400, me);             
}
void del_temp(object me) {me->delete_temp("job_asked");}

int wait_target(object ob, object me)
{
   object obj;
   if(!objectp(present(me, environment(ob)))){
       message_vision("$N˵����Ү���Ǽһ���ô�����ˣ�\n", ob);
       remove_call_out("do_back");
       do_back(ob);
       return 1;
       }
   if(!objectp(ob = present("ma chou", environment(me)))){ 
       tell_object(me,"�㷢����𲻼��ˣ�ֻ��ת���뿪��\n");
       tell_room(environment(me), me->name()+"ͻȻһ��ãȻ�ı��飬��������Ҫ�뿪�ˡ�\n", ({ me }));
       me->delete_temp("rob_job");
       me->clear_condition("rob_task");
       me->delete_temp("wait_target");
       return 1;
       }

    obj = new(__DIR__"shangdui");
    obj->move(environment(me)); 
    obj->set("arg", ob->query_temp("dest"));
    message_vision(HIY"\nֻ��һ������������һֻ�����ھֵ��ڶӳ�������ǰ��\n\n"NOR, ob);
    tell_object(me,"�������ڳ����ˣ�\n"); 
    message_vision(HIY"$N����$n����������������(qiang)�ڶӣ������Ը������ˣ�\n"NOR, ob, me); 
    message_vision("˵��$N�ͳ���ǰȥ���ͼ���������ʦ��׷���ˡ�\n", ob);   
    remove_call_out("do_back");
    do_back(ob);
    me->delete_temp("wait_target");
    me->set_temp("rob_start", 1);
}