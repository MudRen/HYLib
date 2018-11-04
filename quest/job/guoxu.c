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
        set_name("����", ({ "guo xu", "guo"}) );
        set("gender", "����" );
        set("nickname", "�����ھ�");
        set("age", 31);
        set("long", "���ǳ����ھֵ��پ������񣬽����������������࣬���Գ��ڶ��ܰ�ȫ��\n");
        set("str", 29);
        set("dex", 26);
        set("con", 24);
        set("int", 22);
        set("per", 38);
        set("shen", 7500);
        set("max_qi", 2000);
        set("max_jing", 2000);
	 set("neili",2000);
	 set("max_neili",2000);
        set("eff_jingli", 1800);
	 set_skill("blade",100);
	 set_skill("zixia-shengong",200);
	 set_skill("fanliangyi-dao",100);
	 map_skill("blade","fanliangyi-dao");
	 
        set("combat_exp", 1000000);
        set("chat_chance_combat", 55);
        set("chat_msg_combat", ({
                (: perform_action, "blade.sanshen" :),
        }));
        set("inquiry", ([
                "����" : (: ask_job :),
                "����" : (: ask_job :),
                "job" : (: ask_job :),
        ]));        
        setup();
        carry_object("/clone/weapon/gangdao")->wield();
        carry_object("/clone/cloth/cloth")->wear();
        add_money("silver", 20);
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
 
    if(me->query_condition("job_busy"))
            return "�����ڻ������������Ȼ�������ɡ�";       
    if(me->query_temp("on_biao")) 
            return "�ٺ٣������ϲ�����һ��������";
 	if(ob->query_temp("gived"))
		return "����û���ڿ������㱣��";
    if(me->query("shen") < 10000) return "�ߣ��������������̫�ã�������û�˿����㡣";
       if(me->query("balance") < 1000000) return "��һ�����⣬�ҿ���û����������";

    me->set_temp("on_biao", 1);
    message_vision(CYN"\n$N���˵ص�����������Ҳ�������������԰�\n",ob);
    
    me->set_temp("end_place", aquest["start"]);
    me->set_temp("biao_place", aquest["place"]);
    me->start_busy(4);
	ob->set_temp("gived",1);
    remove_call_out("ready");
    call_out("ready", 2, me); 
    remove_call_out("clear");
    call_out("clear",900,ob);
	return "������һ��������"+me->query_temp("biao_place")+"����Ҫ����·�ϵİ�ȫ�������в��\n";    
}
void ready(object me)
{	object biaoshi,cart,biaoshi1;
	cart=new(__DIR__"cart");
       message_vision("�����һ����������$N���\n", me);       
       cart->move(me);
	biaoshi=new(__DIR__"biaoshi1");
	biaoshi->move(environment(me));
	biaoshi1=new(__DIR__"biaoshi1");
	biaoshi1->move(environment(me));
	biaoshi->set_leader(me);
	biaoshi1->set_leader(me);
	message_vision("������������������,ǧ��Ҫ������������\n",me);
	
}
void clear(object ob)
{
ob->delete_temp("gived");
}